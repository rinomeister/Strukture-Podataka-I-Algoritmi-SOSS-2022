#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* prvistring, char* drugistring)
{
    int pocetak,kraj= 0;
    
    int brojac = strlen(prvistring);
    kraj = brojac - 1;

    for (pocetak = 0; pocetak < brojac; pocetak++)
    {
        drugistring[pocetak] = prvistring[kraj];
        kraj--;
    }
    drugistring[pocetak] = '\0';
}

int main()
{
    char prvistring[1000];
    char drugistring[1000];
    printf("Unesi string!\n");
    gets(prvistring);
    reverse(prvistring,drugistring);
    printf("okrenuti string je %s\n",drugistring);
}