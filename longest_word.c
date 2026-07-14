#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000];
    fgets(sentence, 1000, stdin);
    for (int i = 0; sentence[i]; i++)
    {
        if (sentence[i] == '\n')
        {
            sentence[i] = 0;
            break;
        }
    }
    char longest[200] = "";
    int arr[50];

    int i = 0;
    int count = 0;
    int arr_count = 0;
    while (sentence[i] != '\0')
    {
        int lastword = 0;
        int all_wrdd_except_last = 0;
        if (sentence[i] == ' ')
        {
            arr[arr_count] = count;
            arr_count++;
            count = -1;
        }
        count++;
        i++;
    }
    arr[arr_count] = count;
    arr_count++;

    int max = arr[0];
    int index = 0;

    for (int j = 0; j < arr_count; j++)
    {
        if (max < arr[j])
        {
            max = arr[j];
            index = j;
        }
    }

    int lenght_sum = 0;
    for (int i = 0; i < index; i++)
    {
        lenght_sum = lenght_sum + arr[i];
    }

    if (index != 0)
    {
        for (int i = 1; i < index; i++)
        {
            lenght_sum++;
        }
    }
    else if (index == 0)
    {
        lenght_sum--;
    }

    char *ptr_longest = longest;
    char *ptr_sentence = sentence;
    for (int i = 0; i <= lenght_sum; i++)
    {
        ptr_sentence++;
    }

    for (int i = 0; i < max; i++)
    {
        *ptr_longest = *ptr_sentence;
        ptr_longest++;
        ptr_sentence++;
    }
    ptr_longest = longest;

    for (int i = 0; i < max; i++)
    {
        printf("%c", *ptr_longest);
        ptr_longest++;
    }

    return 0;
}
