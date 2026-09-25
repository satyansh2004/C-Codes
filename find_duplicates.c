#include <stdio.h>
#include <stdlib.h>

int *find_duplicates(int *arr, int n, int *result_size)
{
    if (n <= 0)
    {
        printf("No elements in array\n");
        return 0;
    }

    int *dynamic_arr = (int *)malloc(n * sizeof(int));
    int *ptr = dynamic_arr;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {

                *dynamic_arr = arr[i];
                dynamic_arr++;
                count++;
            }
        }
    }

    dynamic_arr = ptr;

    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (dynamic_arr[i] == dynamic_arr[j])
            {
                dynamic_arr[j] = dynamic_arr[j + 1];
            }
        }
    }

    int i = 0;
    while (dynamic_arr[i] != 0)
    {
        i++;
    }

    *result_size = i;

    return dynamic_arr;
}

int main()
{
    int arr[10] = {10, 5, 7, 10, 3, 5, 10, 7, 8, 3};

    int result_size = 0;
    int *print_arr = find_duplicates(arr, 10, &result_size);

    int *temp = print_arr;

    for (int i = 0; i < result_size; i++)
    {
        printf("%d ", *print_arr);
        print_arr++;
    }

    free(temp);

    return 0;
}