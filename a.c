// #include <stdio.h>
// #include <string.h>

// int main()
// {

//     char input[100];
//     scanf("%s", &input);

//     int count = 0;
//     while (input[count] != '\0')
//     {
//         count++;
//     }

//     int freq = 0;
//     for (int i = 0; i < count; i++)
//     {
//         char ch = input[i];
//         for (int j = 0; j < count; j++)
//         {
//             if (ch == input[j])
//             {
//                 freq++;
//             }
//             if (freq > 1)
//             {
//                 continue;
//             }
//         }
//         printf("%c\n", input[i]);
//     }

//     printf("Freq: %d", freq);

//     return 0;
// }

#include <stdio.h>

int main()
{
    int number = 42;
    char letter = 'X';

    int *num_ptr = &number;
    int *char_ptr = &letter;

    printf("Address of number: %p\nAddress of letter: %p", num_ptr, char_ptr);
    return 0;
}