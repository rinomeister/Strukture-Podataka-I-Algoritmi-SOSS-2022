#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mystrstr(char* prvistring, char* drugistring)
{
    int glavnaduljina = strlen(prvistring) - strlen(drugistring) + 1;

    for (int i = 0; i < glavnaduljina; i++)
    {
        int flag = 1;
        for (int j = 0; j < strlen(drugistring); j++)
        {
            if (prvistring[i + j] != drugistring[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            return prvistring + i;
        }
    }
    return NULL;
}
int main()
{
    char* prvi_string, * drugi_string;

    prvi_string = malloc(20 * sizeof(char));
    drugi_string = malloc(20 * sizeof(char));

    printf("Unesite prvi string: \n");
    scanf("%s", prvi_string);

    printf("Unesite drugi string: \n");
    scanf("%s", drugi_string);

    printf("%s\n", mystrstr(prvi_string, drugi_string));

    return 0;
}