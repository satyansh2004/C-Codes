#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    char strings[30];

    printf("Enter Binary Number: ");
    scanf("%s", &strings);

    if (strlen(strings) > 30)
    {
        printf("Error: Cannot enter value of length more than %d", 30);
    }
    else
    {
        int array[strlen(strings)];

        int count = 0;
        int sum = 0;
        for (int i = strlen(strings) - 1; i >= 0; i--)
        {

            int num = strings[i] - '0';

            int power = pow(2, count);

            int eachValue = num * power;
            sum = sum + eachValue;
            count++;
        }

        printf("Binary num %s to Decimal: %d\n", strings, sum);
    }
}