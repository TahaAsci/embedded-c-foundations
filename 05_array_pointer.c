#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t buffer[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {
        printf("Index[%d]: bracket=%u, pointer=%u, address=%p\n",
                i,
                buffer[i],              
                *(buffer+i),               
                (void *)(buffer+i));       
    }

    return 0;
}