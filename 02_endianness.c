#include<stdio.h>
#include<stdint.h>


int main(){

    uint32_t x = 0x11223344;



   if (*(uint8_t *)&x == 0x44) {
        printf("sistem little-endian");
    
    }
    else if (*(uint8_t *)&x == 0x11) {

        printf("sistem big-endian");
    
    }






    return 0;
}