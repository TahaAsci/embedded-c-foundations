#include <stdio.h>
#include <stdint.h>


void led_on(void) {
    printf("LED ON\n");
}

void led_off(void) {
    printf("LED OFF\n");
}


void execute(void (*func_ptr)(void)) {
    if (func_ptr != NULL) { 
        func_ptr();
    }
}

int main(void) {
    
    void (*action)(void) = NULL;

    printf("Doğrudan Pointer Atamasi \n");


    action = led_on;
    action(); 


    action = led_off;
    action();

    printf("\nExecute Fonksiyonu \n");

  
    execute(led_on);
    execute(led_off);

    return 0;
}