#include <stdio.h>
#include <string.h>

int main(void)
{
    char num[20], revNum[20];
    int index = 0;
    int flag = 0;

    printf("Enter number for palindrome check: ");
    scanf("%s", &num);

    for (int i = strlen(num) - 1; i >= 0; i--)
    {
        revNum[index] = num[i];
        index = index + 1;
    }

    revNum[strlen(num)] = '\0';

    printf("Rev Num: %s", revNum);

    for (int i = 0; i < strlen(num); i++)
    {
        if (num[i] == revNum[i])
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }

    if (flag == 0)
    {
        printf("\nNot Palindrome");
    }
    else
    {
        printf("\nPalindrome");
    }
}