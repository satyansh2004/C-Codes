#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[500];
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = 0;

    int i = 0;
    int count = 0;
    while (sentence[i] != '\0')
    {
        if (sentence[i] == ' ')
        {
            count++;
        }
        i++;
    }

    printf("\n%d words", count + 1);

    return 0;
}
