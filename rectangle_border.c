#include <stdio.h>

int main()
{
    int width, height;
    scanf("%d", &width);
    scanf("%d", &height);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1)
            {
                printf("*");
            }
            else
            {
                if (j == 0 || j == width - 1)
                {
                    printf("*");
                }
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
