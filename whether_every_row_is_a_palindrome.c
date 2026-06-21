#include <stdio.h>

int palindrom(int arr[][5], int rows, int cols)
{
    if (cols % 2 != 0)
    {
        int mid = cols / 2;
        int before_mid[((cols - 1) / 2) * 2];
        int *ptr_b = before_mid;
        int after_mid[((cols - 1) / 2) * 2];
        int *ptr_a = after_mid;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (j < mid)
                {
                    *ptr_b = *(*(arr + i) + j);
                    ptr_b++;
                }
                if (j > mid)
                {
                    *ptr_a = *(*(arr + i) + j);
                    ptr_a++;
                }
            }
        }
        ptr_b = before_mid;
        ptr_a = after_mid;

        int flag = 0;
        ptr_a++;
        for (int i = 0; i < ((cols - 1) / 2); i++)
        {

            for (int j = 0; j < ((cols - 1) / 2); j++)
            {
                if (*ptr_b == *ptr_a)
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
                ptr_b++;
                ptr_a--;
            }

            ptr_a = after_mid;
            for (int k = 0; k < (cols - 2); k++)
                ptr_a++;

            if (flag == 1)
            {
                printf("\nRow %d is Palindrome", i + 1);
            }
            else
            {
                printf("\nRow %d is not Palindrome\n", i + 1);
            }
        }
    }

    return 0;
}

int main(void)
{
    int arr[2][5] = {{1, 2, 3, 2, 1}, {4, 5, 6, 7, 8}};

    int rows = 2;
    int cols = 5;

    palindrom(arr, rows, cols);
    return 0;
}