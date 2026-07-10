#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = n; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
