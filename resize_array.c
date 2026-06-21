#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int size, resize;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int *array = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        *(array + i) = i;
    }

    printf("Old Array: [ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", (*(array + i) + 1) * 10);
    }
    printf("]");

    printf("\n\nEnter new size of array: ");
    scanf("%d", &resize);

    int *temp = (int *)realloc(array, resize * sizeof(int));

    if (temp != NULL)
    {
        array = temp;
        free(array);
        for (int i = 0; i < resize; i++)
        {
            *(array + i) = i;
        }

        printf("New Array: [ ");
        for (int i = 0; i < resize; i++)
        {
            printf("%d ", (*(array + i) + 1) * 10);
        }
        printf("]");

        free(temp);
    }

    return 0;
}