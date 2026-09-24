#include <stdio.h>
#include <math.h>

int size(int num, int arr[]);
int result(int arr[]);
int mainfunc(int arr[]);

int main()
{
    int num = 12004;
    int arr[5];
    size(num, arr);
    mainfunc(arr);
    printf("Rsult: %d", result(arr));
    return 0;
}

int size(int num, int arr[])
{
    int count = 0;
    while (num != 0)
    {
        arr[count] = num % 10;
        num = num / 10;
        count++;
    }

    return count;
}

int mainfunc(int arr[]) {
    for (int i = 0; i < 5; i++) {
        if (arr[i] == 0) {
            arr[i] = 5;
        }
    }

    int power = 0;
    for (int i = 0; i < 5; i++) {
        int result = (int)(round(pow(10, power)));
        arr[i] = arr[i] * result;
        power++;
    }

    return 0;
}

int result(int arr[])
{
    int answer = 0;
    for (int i = 4; i >= 0; i--)
    {
        answer = answer + arr[i];
    }

    return answer;
}

