#include <stdio.h>

int diff(int arr[][4], int rows)
{
    int smallest[rows];
    int maximum[rows];

    int max_min_diff[rows];

    for (int i = 0; i < rows; i++)
    {
        int max = *(*(arr + i));
        int min = *(*(arr + i));
        for (int j = 0; j < 4; j++)
        {
            if (*(*(arr + i) + j) > max)
            {
                max = *(*(arr + i) + j);
            }
            if (*(*(arr + i) + j) < min)
            {
                min = *(*(arr + i) + j);
            }
            maximum[i] = max;
            smallest[i] = min;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        max_min_diff[i] = maximum[i] - smallest[i];
    }

    for (int i = 0; i < rows; i++)
    {
        printf("Difference between maximum and smallest element in row %d: %d\n", i, max_min_diff[i]);
    }

    return 0;
}
int main(void)
{
    int arr[3][4] = {{2, 1, 4, 2}, {6, 8, 7, 22}, {9, 12, 10, 12}};
    int rows = 3;

    diff(arr, rows);
    return 0;
}