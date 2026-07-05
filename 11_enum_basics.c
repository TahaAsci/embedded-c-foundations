#include<stdio.h>
#include<stdint.h>

typedef enum {

    STATE_IDLE =0,
    STATE_RUNNIG =1,
    STATE_ERROR =2


}system_state_t;

void print_state(system_state_t state){
    switch (state)
    {
    case STATE_IDLE:
        printf("Sistem Durumu: Boşta (IDLE)\n");
        break;
    case  STATE_RUNNIG:

        printf("Sistem Durumu: Çalışıyor (RUNNING)\n");
        break;
    case  STATE_ERROR:
        printf("Sistem Durumu: Hata (ERROR)!\n");
        break;
    default:
        printf("Sistem Durumu: Bilinmeyen Durum!\n");
        break;
    }
}


int main(){

system_state_t current_state =STATE_IDLE;
print_state(current_state);

current_state = STATE_RUNNIG;
print_state(current_state);

current_state = STATE_ERROR;
print_state(current_state);














    return 0;
}