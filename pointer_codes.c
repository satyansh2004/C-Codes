#include <stdio.h>

int main(void)
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int reversed_array[10] = {10, 20, 30};

    for (int i = 9; i >= 0; i--)
    {
        int *ptr = &array[i];
        // printf("%d ", *ptr);

        for (int j = 0; j < 3; j++)
        {
            int *ptr2 = &reversed_array[j];
            ptr2 = *ptr;
            printf("%d ", *ptr2);
        }
        break;
    }
}
