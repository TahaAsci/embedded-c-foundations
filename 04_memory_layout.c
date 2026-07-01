#include <stdio.h>
#include <stdint.h>


int main(){

    uint32_t p = 0xDEADBEEF;

    printf("Byte[0] = 0x%02X\n", *((uint8_t *)&p + 0));
    printf("Byte[1] = 0x%02X\n", *((uint8_t *)&p + 1));
    printf("Byte[2] = 0x%02X\n", *((uint8_t *)&p + 2));
    printf("Byte[3] = 0x%02X\n", *((uint8_t *)&p + 3));

    uint8_t  buffer[4];
    uint32_t val = 0;

    printf("Address of buffer: %p\n", (void *)buffer);
    printf("Address of val:    %p\n", (void *)&val);

    return 0;
}