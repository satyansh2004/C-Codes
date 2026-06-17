#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int size, sum = 0;

    printf("Enter Array Size: ");
    scanf("%d", &size);

    int *ptr = (int *)malloc(size);

    for (int i = 0; i < size; i++)
    {
        ptr[i] = i + 1;
    }

    for (int i = 0; i < size; i++)
    {
        sum = sum + *ptr;
        ptr++;
    }

    printf("Sum: %d", sum);
    return 0;
}