#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mystrcpy(char* prvistring, char* drugistring)
{
    int i = 0;
    while (drugistring[i] != '\0')
    {
        prvistring[i] = drugistring[i];
        i++;
    }
    prvistring[i] = '\0';
}

int main()
{
    char prvistring[] = "recenicajedan";
    char drugistring[] = "recenicadva";
    mystrcpy(prvistring, drugistring);
    printf("Kopirani string je %s\n", prvistring);
    printf("Kopirani string je %s\n"),strcpy(prvistring,drugistring);
}