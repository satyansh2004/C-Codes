#include <stdio.h>

int largest(int *ptr1, int *ptr2)
{
    if (*ptr1 == *ptr2)
    {
        printf("\nBoth are equal\n");
    }
    else if (*ptr1 > *ptr2)
    {
        printf("\nNum1 is Bigger\n");
    }
    else
    {
        printf("\nNum2 is Bigger\n");
    }
    return 0;
}

// Increment every element of an array using only pointer arithmetic.
void array_increment()
{

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int *ptr;
    printf("\n[ ");
    for (int i = 0; i < 10; i++)
    {
        ptr = &arr[i];
        *ptr = *ptr + 1;
        printf("%d ", *ptr);
    }
    printf("]");
}

int main(void)
{
    // Printing a variable's pointer value and address

    int a = 10;
    int *ptr = &a;

    printf("The value of int a is: %d\nThe address of int a is: %p\nAdress of pointer is: %p", *ptr, (void *)ptr, (void *)&ptr);

    // Modifying a Variable with pointer
    int b = 20;
    int *ptrb = &b;

    *ptrb = 30;

    printf("\n\nChanged Value: %d", *ptrb);

    // Swaping two integers with pointers
    int x = 10;
    int y = 20;
    int z;
    printf("\n\nBefore Swapping: %d, %d", x, y);

    int *temp;
    temp = &x;

    int *temp2;
    temp2 = &y;

    int *temp3;
    temp3 = &z;

    *temp3 = x;
    *temp = y;
    *temp2 = z;
    printf("\nAfter Swapping: %d, %d", x, y);

    // Largest of Two using pointer Parameters
    int num1, num2;
    printf("\n\nEnter two numbers: ");
    scanf("%d%d", &num1, &num2);
    largest(&num1, &num2);

    array_increment();
}