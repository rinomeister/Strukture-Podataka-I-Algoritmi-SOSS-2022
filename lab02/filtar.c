#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *filtriraj (int *niz, int n, int th, int *nth);

int main()
{
    int niz[] = {10,20,30,40,50,60,70,80,90};
    int nth = 0;//duzina novog niza sa brojevima koji su prosli filtar
    int th = 61; //trazimo brojeve manje od ovog broja
    int n = 10;//velicina niza
    int* noviNiz = filtriraj(niz, n, th, &nth);//poziv funkcije
    printf("Brojevi koji su prosli kroz filter su \n");
    for (int i = 0; i < nth; i++)
    {
        printf("%d\n",noviNiz[i]); //funckija za print novog niza
    }
    return 0;

}
int *filtriraj (int *niz, int n, int th, int *nth)
{
    int j = 0;
    for (int i = 0; i < n; i++)//for petlja koja ide po nizu
    {
        if(niz[i]<th)
        {
            *nth+=1;
        }
    }
	int* noviNiz = (int*)malloc((*nth) * sizeof(int));//dinamicka alokacija novog niza koji ce spremati filtrirane brojeve
    for (int i = 0; i < n; i++)
    {
        if(niz[i]<th)//petlja koja provjerava jeli vrijednost indexu niza manji od zadanog filtra ako je doda se u novi niz i nastavi
        {
            noviNiz[j] = niz [i];
			j++;
        }
    }
    return noviNiz;

    
    
}