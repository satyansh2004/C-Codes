#include <stdio.h>

int my_strlen(char *str)
{
    char *ptr = str;
    int length = 0;
    while (*ptr != '\0')
    {
        length = length + 1;
        ptr++;
    }

    return length;
}
int main(void)
{
    char str[] = "Hello";

    printf("%d", my_strlen(str));
    return 0;
}