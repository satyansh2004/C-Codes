#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000];
    fgets(sentence, 1000, stdin);
    sentence[strcspn(sentence, "\n")] = 0;

    int count = 0;
    while (sentence[count] != '\0')
    {
        count++;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        printf("%c", sentence[i]);
    }
    return 0;
}
