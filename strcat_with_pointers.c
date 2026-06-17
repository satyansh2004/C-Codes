#include <stdio.h>

int length(char *dest, char *src)
{
    int strLen = 0;

    char *ptr = dest;
    char *ptr2 = src;

    while (*ptr != '\0')
    {
        strLen++;
        ptr++;
    }

    while (*ptr2 != '\0')
    {
        strLen++;
        ptr2++;
    }

    return strLen;
}
char *my_strcat(char *dest, char *src)
{
    char *ptr = dest;
    char *ptr2 = src;

    char strcat[length(dest, src)];
    char *ptr3;
    ptr3 = strcat;

    while (*ptr != '\0')
    {
        *ptr3 = *ptr;
        ptr++;
        ptr3++;
    }

    while (*ptr2 != '\0')
    {
        *ptr3 = *ptr2;
        ptr2++;
        ptr3++;
    }

    for (int i = 0; i < length(dest, src); i++)
    {
        printf("%c", strcat[i]);
    }
}
int main(void)
{

    char dest[] = "Hello ";
    char src[] = "World";

    my_strcat(dest, src);

    return 0;
}
