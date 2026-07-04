#include<stdio.h>
#include<stdint.h>

//sıcaklık
void print_temperature(uint32_t value){
    printf("[sensor]Sicaklik degeri: %u Celcius\n",value);
}

//basıç
void print_pressure(uint32_t value) {
    printf("[SENSOR] Basinc Degeri: %u hPa\n", value);
}


void process_sensor_data(void *data,void(*action)(uint32_t)){

    if(data == NULL || action == NULL){
        printf("Hata: Gecersiz veri veya aksiyon!\n");
        return;
    }

    uint32_t sensor_value = *((uint32_t*)data);

    action(sensor_value);
}



int main(){

    uint8_t temp_buffer[4] = {25, 0x00, 0x00, 0x00}; 

    uint8_t press_buffer[4] = {0xF5, 0x03, 0x00, 0x00};


    process_sensor_data(temp_buffer, print_temperature);

    process_sensor_data(press_buffer, print_pressure);
 
    printf("\n--- Guvenlik Testi ---\n");

    process_sensor_data(NULL, print_temperature); /* Veri yok! */
    


    return 0;
}