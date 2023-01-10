#include "functioncalls.h"
#include <stdio.h>
#include <stdlib.h>

/*•	Funkciju koja čita binarnu STL datoteku i vraća ispunjenu Objekt3D  strukturu*/
Objekt3D* citaj()
{
    FILE* fp = fopen("primjerbin.stl","rb"); //otvaranje datoteke sa read u binary formatu
    if (!fp)
    {
        printf("ERROR\n");     //error print ako nemozemo otvorit datoteku
        return 0;
    }
	Objekt3D* objekt = (Objekt3D*)malloc(sizeof(Objekt3D)); //ispunjena objekt struktura koju cemo vracat
    fseek(fp, sizeof(char) * 80, SEEK_SET); //•	Zaglavlje je dugo 80 byte-ova i može biti ignorirano pri čitanju i 
    //ispunjeno nulama pri stvaranju datoteke. Nakon toga se nalazi broj trokuta u datoteci (unsigned int).
    //koristimo fseek da se pomaknemo od 80 bajtova jer je to zaglavlje
	fread((&(objekt->BrojTrokuta)), sizeof(unsigned int), 1, fp);
    //fread da citamo od 80 bajta pa nadalje
	objekt->NizTrokuta = (Trokut*)malloc(sizeof(Trokut)*(objekt->BrojTrokuta));//dinamicko alociranje
    for (int i = 0; i < objekt->BrojTrokuta; i++)       //for petlja koja ide onoliko puta koliko ima trokuta
	{
		fread(&(objekt->NizTrokuta[i]), 50, 1, fp); //za svaku iteraciju ucitan jedan element velicine 50 iz fp u niz trokuta
        
	}
	fclose(fp);
	return objekt;
}
//Funkciju koja Objekt3D strukturu zapisuje u binarnu STL datoteku
int pisi(Objekt3D* objekt)
{
    FILE* fp = fopen("primjerbin.stl", "rb"); //otvaramo u read binary modu
    FILE* fpmoj = fopen("xymoj.stl", "wb");
    //char temp = 0;
    if (!fp)
	{
		printf("ERROR\n");
		return 0;//1
	}
    if (!fpmoj)
	{
		printf("ERROR\n");
		return 0;
	}
    char buffer[80] = { 0 }; 
    //buffer cemo koristit da u njega spremimo ono sta cemo procitat sa fread pa spremit u fwrite
    for (int i = 0; i < objekt->BrojTrokuta; i++)
	{
		fwrite(&(objekt->NizTrokuta[i]), 50, 1, fpmoj);
	}
	return 0;
}

//•	Funkcija koja Objekt3D strukturu zapisuje u tekstualnu STL datoteku
int pisitxt(Objekt3D* objekt)
{
    int i = 0, j = 0, k = 0;
    FILE* fp = fopen("primjertxt.stl", "wt");//write text mode
    FILE* fpmoj = fopen("xymoj.stl", "wt");
    if(!fp)
    {
        printf("ERROR\n");
        return 0;
    }
    if(!fpmoj)
    {
        printf("ERROR\n");
        return 0;
    }
    for (int i = 0; i < objekt->BrojTrokuta; i++)
    {
        fprintf(fpmoj, "  facet %f %f %f\n", objekt->NizTrokuta[i].normala[0], objekt->NizTrokuta[i].normala[1],objekt->NizTrokuta[i].normala[2]);
        fprintf(fpmoj, "    outer loop\n");
        for (int j = 0; j < 3; j++)
        {
            fprintf(fpmoj, "      vertex %f %f %f\n", objekt->NizTrokuta[i].tocka[i].x, objekt->NizTrokuta[i].tocka[i].y, objekt->NizTrokuta[i].tocka[i].z);
            fprintf(fpmoj, "    endloop\n");
            fprintf(fpmoj, "  endfacet\n");
        }
    }
    return 0;
}

//•	Funkciju koja briše Objekt3D strukturu
void brisiObjekt3D(Objekt3D* objekt)
{
	free(objekt->NizTrokuta);
	free(objekt);
}

