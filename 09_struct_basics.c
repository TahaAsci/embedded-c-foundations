#include<stdio.h>
#include<stdint.h>

 /*typedef struct __attribute__((packed))
{
    uint8_t id;
    uint16_t temperature;
    uint32_t pressure;
} SensorData_t;*/

typedef struct  //largest to smallest best
{
    uint32_t pressure;
     uint16_t temperature;
     uint8_t id;
}SensorData_t;




 void print_sensor(SensorData_t *sensor){

    if(sensor==NULL){
        printf("Hata: Sensor pointer bos!\n");
        return;
    }   
        printf("Sensor ID: %u\n", sensor->id);
        printf("Sicaklik: %u Celcius\n", sensor->temperature);
        printf("Basinc: %u hPa\n", sensor->pressure);

 }



int main(){

    SensorData_t data1;

    data1.id = 1; 
    data1.temperature = 25;  
    data1.pressure = 1013;

    print_sensor(&data1);

    printf("sizeof uint8_t:  %zu\n", sizeof(uint8_t));
    printf("sizeof uint16_t: %zu\n", sizeof(uint16_t));
    printf("sizeof uint32_t: %zu\n", sizeof(uint32_t));
    printf("sizeof SensorData_t: %zu\n", sizeof(SensorData_t));


    return 0;
}