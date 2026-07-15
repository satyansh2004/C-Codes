#include <stdio.h>

int main()
{
    long long n;
    scanf("%lld", &n);

    int steps = 0;

    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else if (n % 2 != 0)
        {
            n = n * 3 + 1;
        }

        steps++;
    }

    printf("Steps: %d", steps);
    return 0;
}
