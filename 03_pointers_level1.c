#include <stdio.h>
#include <stdint.h>

void swap(uint32_t *p1, uint32_t *p2) {
    if (p1 == NULL || p2 == NULL) {
        return;
    }

    uint32_t temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    uint32_t a = 10;
    uint32_t b = 20;
    
    printf("Before: a = %u, b = %u\n", a, b);
            
    swap(&a, &b);

    printf("After:  a = %u, b = %u\n", a, b);

    return 0;
} 