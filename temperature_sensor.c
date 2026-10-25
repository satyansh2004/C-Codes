#include <stdio.h>

#define BUFFER_SIZE 5

typedef struct
{
    signed int temp;
} TEMPRATURE_SENSOR;

void init_sensor(TEMPRATURE_SENSOR *temp_sensor);
void display_readings(TEMPRATURE_SENSOR *temp_sensor);

int main()
{
    TEMPRATURE_SENSOR temp_sensor[BUFFER_SIZE];
    while (1)
    {
        int choice;
        printf("\nChoose your option\n1 - Initialize Readings\n2 - Display Readings\n3 - Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            init_sensor(temp_sensor);
            break;

        case 2:
            display_readings(temp_sensor);
            break;

        case 3:
            return 1;

        default:
            printf("Not a valid choice!!");
            break;
        }
    }

    return 0;
}

void init_sensor(TEMPRATURE_SENSOR *temp_sensor)
{
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        temp_sensor[i].temp = 10;
        printf("Index: %d, Value: %d\n", i, temp_sensor[i].temp);
    }
}

void display_readings(TEMPRATURE_SENSOR *temp_sensor)
{
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        printf("%d ", temp_sensor[i].temp);
    }
}