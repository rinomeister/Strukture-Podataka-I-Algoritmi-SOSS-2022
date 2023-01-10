#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mystrlen(char* stringerino)
{
    int duljina = 0;
    for (int i = 0; stringerino[i] != '\0'; i++)
    {
        duljina++;
    }
    return duljina;
}

int main()
{
    char stringerino[] = "recenica";
    printf("Duljina stringa je %d\n", mystrlen(stringerino));
    printf("Duljina stringa je %d\n", strlen(stringerino));
}
//RADI
