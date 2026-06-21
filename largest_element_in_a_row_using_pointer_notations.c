#include <stdio.h>

int maxElement(int arr[][4], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        int max = *(*(arr + i));

        for (int j = 1; j < 4; j++)
        {
            if (*(*(arr + i) + j) > max)
            {
                max = *(*(arr + i) + j);
            }
        }

        printf("Largest in row %d = %d\n", i, max);
    }

    return 0;
}

int main(void)
{
    int rows = 3;
    int arr[3][4] = {{1, 2, 5, 4}, {9, 8, 6, 32}, {11, 0, 21, 7}};

    maxElement(arr, rows);
    return 0;
}