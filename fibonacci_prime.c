// Print the first N Fibonacci numbers that are also prime numbers.
#include <stdio.h>

int main(void)
{
    int n, a = 0, b = 1, c;
    int count = 0;

    int fib[50];
    int notPrimeFib[50];
    int primeFib[50];

    fib[0] = a;
    fib[1] = b;

    printf("Enter number of iterations: ");
    scanf("%d", &n);

    for (int i = 2; i < n + 2; i++)
    {
        c = a + b;

        fib[i] = c;

        a = b;
        b = c;
    }

    // Checking prime numbers from fib[] array
    for (int i = 0; i < n; i++)
    {

        if (fib[i] == 1 || fib[i] == 2 || fib[i] == 3)
        {
            primeFib[count] = fib[i];
            count = count + 1;
        }
        else
        {
            for (int j = 2; j < i; j++)
            {
                if (fib[i] % j == 0)
                {
                    break;
                }
                else
                {
                    primeFib[count] = fib[i];
                    count = count + 1;
                    break;
                }
            }
        }
    }

    // Printing Prim Fibonacci Numbers
    printf("\n[ ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", primeFib[i]);
    }
    printf("]");
}