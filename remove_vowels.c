#include <stdio.h>

void main()
{
    char str[13] = {'g', 'e', 'e', 'k', 's', 'f', 'o', 'r', 'g', 'e', 'e', 'k', 's'};

    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            str[i] = ' ';
        }
        else if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            str[i] = ' ';
        }

        i++;
    }

    int j = 0;

    while (str[j] != '\0')
    {
        if (str[j] != ' ') {
            printf("%c", str[j]);
        }
        j++;
    }
}