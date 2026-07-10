#include <stdio.h>

int main()
{
    int total;
    scanf("%d", &total);

    int hr = 0, min = 0, sec = 0;

    if (total > 60)
    {
        min = total / 60;
        sec = total - (min * 60);
    }

    if (min > 60)
    {
        hr = min / 60;
        min = min - (hr * 60);
    }

    printf("%dh %dm %ds", hr, min, sec);
    return 0;
}
