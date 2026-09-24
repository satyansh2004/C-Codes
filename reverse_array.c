#include <stdio.h>

int reverse(int arr[], int size)
{

    int *ptr = arr;
    int *rev_ptr = arr;

    for (int i = 1; i < size; i++)
    {
        rev_ptr++;
    }

    int mid = size / 2;
    for (int i = 0; i < mid; i++)
    {
        int temp = *ptr;
        *ptr = *rev_ptr;
        *rev_ptr = temp;
        ptr++;
        rev_ptr--;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void main()
{
    int arr[6] = {1, 3, 4, 5, 7, 10};
    int size = 6;

    reverse(arr, size);
}