#include <stdio.h>
#include <stdint.h>

// GPIO Mod Tanımlamaları
typedef enum {

    GPIO_INPUT=0,
    GPIO_OUTPUT=1,
    GPIO_ANALOG=2,
    GPIO_AF=3
}gpio_mode_t;

//  32-bit tam veya 8-bit parça parça erişim sağlar
typedef union {
    uint32_t word;
    uint8_t bytes[4];

}gpio_reg_t;
 
//Donanım register haritasını simüle eder
typedef struct 
{
    gpio_reg_t MODER;
    gpio_reg_t ODR;
    gpio_reg_t IDR;

}gpio_port_t;

//Hızlı ve Optimize Bitwise GPIO Makroları
#define GPIO_SET(reg,pin) ((reg) |=(1U << (pin)))
#define GPIO_CLEAR(reg,pin) ((reg) &= ~(1U << (pin)))
#define GPIO_TOGGLE(reg,pin) ((reg) ^=(1U << (pin)))
#define GPIO_READ(reg,pin) (((reg) >> (pin)) & 1U)

typedef void (*gpio_callback_t)(uint8_t pin);

static gpio_callback_t irq_handler = NULL;

void gpio_set_mode(gpio_port_t *port, uint8_t pin, gpio_mode_t mode) {
    if (port == NULL) return;
    port->MODER.word &= ~(0x3U << (pin * 2));
    port->MODER.word |=  (mode << (pin * 2));
}

void gpio_write(gpio_port_t *port, uint8_t pin, uint8_t value) {
    if (port == NULL) return;
    if (value) {
        GPIO_SET(port->ODR.word, pin);    
    } else {
        GPIO_CLEAR(port->ODR.word, pin);  
    }
}

void gpio_toggle(gpio_port_t *port, uint8_t pin) {
    if (!port) return;
    GPIO_TOGGLE(port->ODR.word, pin); 
}

uint8_t gpio_read(gpio_port_t *port, uint8_t pin) {
    if (port == NULL) return 0;
    return GPIO_READ(port->IDR.word, pin);  
}

void gpio_attach_interrupt(gpio_callback_t callback) {
    irq_handler = callback;
}
 
void gpio_fire_interrupt(uint8_t pin) {
    if (irq_handler != NULL) {
        irq_handler(pin); 
    }
}

void my_interrupt_handler(uint8_t pin) {
    printf("[IRQ] Pin %u interrupt tetiklendi!\n", pin);
}

int main(void) {

gpio_port_t portA = {0};


gpio_set_mode(&portA, 5, GPIO_OUTPUT);
printf("MODER after set_mode: 0x%08X\n", portA.MODER.word);


gpio_write(&portA, 5, 1);
printf("ODR after write(1):   0x%08X\n", portA.ODR.word);


gpio_toggle(&portA, 5);
printf("ODR after toggle:     0x%08X\n", portA.ODR.word);

gpio_attach_interrupt(my_interrupt_handler);
gpio_fire_interrupt(5);



return 0;
}