#include <stdio.h>

int countVowels(char *str)
{
    char *ptr = str;

    int vowels = 0;
    while (*ptr != '\0')
    {
        if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u')
        {
            vowels = vowels + 1;
        }

        if (*ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U')
        {
            vowels = vowels + 1;
        }
        ptr++;
    }

    return vowels;
}

int main(void)
{
    char str[] = "Programming";

    printf("Vowels: %d", countVowels(str));
    return 0;
}