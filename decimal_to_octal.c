#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    char inputNum[20];
    int display[20];
    int reverseArr[20];

    printf("Enter Decimal Number: ");
    scanf("%s", &inputNum);

    int quotient = 0;
    int sum = 0;
    int mainNum = atoi(inputNum);
    for (int i = 0; i < strlen(inputNum); i++)
    {
        int remainder = mainNum % 8;
        int quotient = mainNum / 8;

        mainNum = quotient;
        display[i] = remainder;
    }

    printf("Decimal to Octal: ");
    for (int i = strlen(inputNum) - 1; i >= 0; i--)
    {
        printf("%d", display[i]);
    }
}