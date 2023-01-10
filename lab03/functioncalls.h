#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
/*Potrebno je definirati strukturu Trokut koja će predstavljati jedan trokut 
sa normalom i sa dodatnim unsigned short brojem (boja trokuta), 
ukupno 50 byte-ova. 
Definirati dodatnu strukturu Objekt3D koja će sadržati niz trokuta i njihov broj. */

typedef struct 
{
	float x, y, z;
}Tocke;

typedef struct 
{
	float normala[3];
	unsigned short int BojaTrokuta;
	Tocke tocka[3];
}Trokut;


typedef struct 
{
	Trokut* NizTrokuta;
	int BrojTrokuta;
}Objekt3D;

Objekt3D* citaj();
int pisi(Objekt3D*);
void brisiObjekt3D(Objekt3D*);
int pisitxt(Objekt3D*);