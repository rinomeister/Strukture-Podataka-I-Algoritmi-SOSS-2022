#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mystrcat(char* prvistring, char* drugistring)
{
	int i;
	int duljinaprvog = strlen(prvistring);
	int duljinadrugog = strlen(drugistring);
	for (i=0; i <= duljinadrugog ; i++)
		prvistring[duljinaprvog + i] = drugistring[i];
	return prvistring;
}

int main()
{
    char prvistring[] = "recenicajedan";
    char drugistring[] = "recenicadva";
    mystrcat(prvistring, drugistring);
    printf("Dodani string je %s\n", prvistring); 
}