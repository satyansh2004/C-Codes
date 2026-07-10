#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;

    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }

    for (int count = i - 1; count >= 0; count--)
    {
        printf("%c", s[count]);
    }

    return 0;
}
