#include <stdio.h>

int rowSum(int arr[][4], int row)
{
    int sum[row];
    int *sumPtr = sum;
    int total = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            total = total + *(*(arr + i) + j);
        }
        *sumPtr = total;
        sumPtr++;
        total = 0;
    }

    sumPtr = sum;
    for (int i = 0; i < row; i++)
    {
        printf("%d ", *sumPtr);
        sumPtr++;
    }

    return 0;
}

int main(void)
{
    int row = 3;
    int arr[3][4] = {{1, 1, 1, 1}, {2, 4, 8, 16}, {3, 9, 27, 81}};

    rowSum(arr, row);

    return 0;
}