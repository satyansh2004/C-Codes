#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char firstName[50], lastName[50];
    printf("Enter firstName: ");
    scanf("%s", firstName);
    printf("Enter lastName: ");
    scanf("%s", lastName);
    char username[100];
    char initials[3];

    // Create username (lowercase, no space)
    int i = 0;
    int count = 0;
    while (firstName[i] != '\0')
    {
        firstName[i] = tolower(firstName[i]);
        username[count] = firstName[i];
        count++;
        i++;
    }

    i = 0;
    while (lastName[i] != '\0')
    {
        lastName[i] = tolower(lastName[i]);
        username[count] = lastName[i];
        count++;
        i++;
    }

    // Create initials (uppercase first letters)
    initials[0] = toupper(firstName[0]);
    initials[1] = toupper(lastName[0]);

    // Print results
    printf("Username: %s\n", username);
    printf("Initials: %s", initials);
    return 0;
}
