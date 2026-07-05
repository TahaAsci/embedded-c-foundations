#include<stdio.h>
#include<stdint.h>
//Union'ın boyutu = en büyük elemanın boyutu
typedef union {
    uint32_t full;      
    uint8_t  bytes[4];  
} register_t;


int main(){

    register_t reg;
    reg.full = 0xDEADBEEF;

    printf("%08X\n",reg.full);
    printf("%02X\n",reg.bytes[0]);
    printf("%02X\n",reg.bytes[1]);
    printf("%02X\n",reg.bytes[2]);
    printf("%02X\n",reg.bytes[3]);
    
    printf("sizeof register_t: %zu\n", sizeof(register_t));

    reg.bytes[0] = 0xAA;
    printf("bytes[0]=0xAA sonrasi full: %08X\n", reg.full);





    return 0;
}