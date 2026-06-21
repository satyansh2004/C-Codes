#include <stdio.h>
#include <stdlib.h>

void *sum_arr(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + *(arr + i);
    }

    printf("Sum: %d\n", sum);
}

void *average(int *arr, int size)
{
    int average = 0;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + *(arr + i);
    }

    average = sum / size;

    printf("Average: %d\n", average);
}

int main(void)
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    int *ptr = arr;
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d value: ", i + 1);
        scanf("%d", ptr);
        ptr++;
    }

    void *(*ptr_func)(int *, int);
    ptr_func = sum_arr;
    ptr_func(arr, n);

    ptr_func = average;
    ptr_func(arr, n);

    free(arr);
    return 0;
}