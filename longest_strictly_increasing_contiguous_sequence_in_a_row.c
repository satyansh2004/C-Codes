#include <stdio.h>

int sequence(int *arr, int size)
{
    int *ptr = arr;
    int array[size], count = 0;
    int *ptr_contiguous = array;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (*ptr < *(ptr + j))
            {
                *ptr_contiguous = *ptr;
                ptr_contiguous++;
                count++;
            }
            else
            {
                break;
            }

            ptr++;
        }
    }

    ptr_contiguous = array;
    printf("Longest strictly increasing contiguous sequence in a row: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", *ptr_contiguous);
        ptr_contiguous++;
    }
    return 0;
}

int main(void)
{
    int arr[] = {1, 2, 3, 8, 4, 5};
    int arr_size = sizeof(arr) / sizeof(int);

    sequence(arr, arr_size);
    return 0;
}