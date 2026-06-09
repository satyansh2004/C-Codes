#include <stdio.h>

int main(void)
{
    int array[10] = {2, 44, 22, 34, 1, 4, 99, 102, 1000, 8};

    int second_bigInt;

    int temp;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    int second_bigInt = array[1];
    printf("Second Big integer: %d", second_bigInt);
}
