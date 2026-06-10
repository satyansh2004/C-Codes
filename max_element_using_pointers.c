#include <stdio.h>

int main(void)
{
    int arr[] = {100, 250, 180, 400, 350};
    int arrLen = sizeof(arr) / sizeof(int);

    int biggestNum;
    int *ptr = arr;
    int *ptr2 = arr;

    int temp;

    for (int i = 0; i < arrLen; i++)
    {
        for (int j = 0; j < arrLen; j++)
        {

            if (*ptr > *ptr2)
            {
                temp = *ptr;
                *ptr = *ptr2;
                *ptr2 = temp;
            }

            ptr2++;
        }
        ptr2 = arr;
        ptr++;
    }
    ptr = arr;
    biggestNum = *ptr;
    printf("\nBiggest Num: %d", biggestNum);
}