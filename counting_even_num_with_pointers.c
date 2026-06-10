#include <stdio.h>

int main(void)
{
    int arr[] = {1, 4, 2, 5, 7, 6, 12, 99, 83, 128};
    int arrLen = sizeof(arr) / sizeof(int);

    int *ptr = arr;
    int total_even_num = 0;
    for (int i = 0; i < arrLen; i++)
    {
        if (*ptr % 2 == 0)
        {
            printf("\n%d is even", *ptr);
            total_even_num = total_even_num + 1;
        }
        ptr++;
    }

    printf("\nTotal Even numbers: %d", total_even_num);
}