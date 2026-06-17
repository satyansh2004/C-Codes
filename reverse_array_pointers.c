#include <stdio.h>

int reverseArray(int *arr, int size)
{
    int *ptr = &arr[size - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d ", *ptr);
        ptr -= 1;
    }

    return 0;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};

    int sizeArr = sizeof(arr) / sizeof(int);
    reverseArray(arr, sizeArr);
    return 0;
}