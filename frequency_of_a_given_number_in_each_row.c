#include <stdio.h>

int frequency(int arr[][4], int rows, int given_num)
{
    int freq_num = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (*(*(arr + i) + j) == given_num)
            {
                freq_num = freq_num + 1;
            }
        }
        printf("Frequency of number %d in row %d: %d\n", given_num, rows, freq_num);
        freq_num = 0;
    }
}

int main(void)
{
    int arr[2][4] = {{1, 2, 4, 4}, {5, 7, 8, 7}};
    int rows = 2;

    int given_num = 7;

    frequency(arr, rows, given_num);
    return 0;
}