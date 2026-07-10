#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char sentence[1000];
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = 0;

    int i = 0;
    while (sentence[i] != '\0')
    {
        sentence[0] = toupper(sentence[0]);
        if (sentence[i] == ' ')
        {
            sentence[i + 1] = toupper(sentence[i + 1]);
        }
        i++;
    }

    printf("%s", sentence);
    return 0;
}
