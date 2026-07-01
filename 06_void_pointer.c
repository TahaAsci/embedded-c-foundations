#include <stdio.h>
#include <stdint.h>

void print_bytes(void *data, size_t size){

        uint8_t *ptr =(uint8_t *)data;

        for(size_t i=0;i < size;i++){

             printf("Byte[%zu] = 0x%02X\n", i,*(ptr+i));
        }




}


 int main(){

    uint32_t val = 0xDEADBEEF;
  
    print_bytes(&val,sizeof(val));

    uint8_t arr[4] = {0x11, 0x22, 0x33, 0x44};

    print_bytes(arr, sizeof(arr));




    return 0;
 }