#include <stdio.h>

void swap_sensor_values(int *sens_1, int *sens_2)
{
    int temp;

    temp = *sens_1;
    *sens_1 = *sens_2;
    *sens_2 = temp;
}

int main(void)
{
    int sensor_1 = 20;
    int sensor_2 = 40;

    printf("----------Before Swapping----------\nSensor 1: %d\nSensor 2: %d", sensor_1, sensor_2);

    swap_sensor_values(&sensor_1, &sensor_2);

    printf("\n\n----------After Swapping-----------\nSensor 1: %d\nSensor 2: %d", sensor_1, sensor_2);
}