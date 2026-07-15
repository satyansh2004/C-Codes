#include <stdio.h>
#include <math.h>

int main()
{
    int n, rev = 0, revs = 0;
    scanf("%d", &n);

    int temp = n;
    int count = 0;
    while (n != 0)
    {
        n % 10;
        n = n / 10;
        count++;
    }

    n = temp;

    int rev_pow = pow(10, count - 1);
    for (int i = 0; i < count; i++)
    {
        revs = n % 10;
        int pows;

        revs = revs * rev_pow;
        rev_pow = rev_pow / 10;
        rev = rev + revs;
        n = n / 10;
    }

    printf("%d", rev);

    return 0;
}
