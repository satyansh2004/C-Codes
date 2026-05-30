#include <stdio.h>

int biggestNum(int num1, int num2, int num3)
{
    int biggestNum = 0;

    if (num1 > num2 && num1 > num3)
    {
        biggestNum = num1;
    }
    else if (num2 > num3)
    {
        biggestNum = num2;
    }
    else
    {
        biggestNum = num3;
    }

    return biggestNum;
}

int main(void)
{
    int num1, num2, num3;

    int countGCD = 0;

    int gcd[50], lcm[50];

    // Taking input from user for 3 numbers
    printf("Enter 3 numbers: ");
    scanf("%d%d%d", &num1, &num2, &num3);

    // Finding largest number among the 3 numbers
    int bigNum = biggestNum(num1, num2, num3);

    // Finding all divisor and pushing to gcd[] array
    for (int i = 1; i <= bigNum; i++)
    {
        if (num1 % i == 0 && num2 % i == 0 && num3 % i == 0)
        {
            gcd[countGCD] = i;
            countGCD = countGCD + 1;
        }
    }

    // Printing all the Divisors of 3 numbers
    printf("All Divisor ARRAY: ");
    for (int i = 0; i < countGCD; i++)
    {
        printf("%d ", gcd[i]);
    }

    // Printing the Greatest Common Divisor (GCD)
    printf("\n\nThe GCD of 3 numbers is: %d\n", gcd[countGCD - 1]);
}