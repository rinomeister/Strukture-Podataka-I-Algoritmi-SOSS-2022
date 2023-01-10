#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Deklarirati strukturu Tocka koja sadrži dva člana: x i y (oba su float). 
typedef struct
{
	float x;
	float y; 
}Tocka;
 
typedef struct
{
	Tocka* Vrh; //niz vrhova pa je pointer
	int n;//broj vrhova
}Poligon;
 
Poligon* novi_poligon(float*, float*, int);//prima niz x i y koordinata i stvara novi poligon koji će kao vrhove imati parove brojeva iz nizova. Nizovi su dužine n (≥ 3).
										
Tocka** pozitivni(Poligon*, int*);// funkcija vraća niz pokazivača na vrhove poligona kojima  su obje koordinate pozitivne. Broj elemenata u nizu će biti spremljen u np parametar.
int main()
{
	int n = 3;//broj vrhova
	int np = 0;//Broj elemenata u nizu će biti spremljen u np parametar.      
	float niz_x[3] = { -1,2,3 };//niz kordinata
	float niz_y[3] = { 11,-22,33 };//niz kordinata
	Poligon* p = novi_poligon(niz_x, niz_y, n);
	Tocka** novaKordinata = pozitivni(p, &np);
	for (int i = 0; i < np; i++)
	{
		printf("%f %f",novaKordinata[i]->x,novaKordinata[i]->y);
	}
	return 0;
}
 
Poligon* novi_poligon(float* niz_x, float* niz_y, int n)
{
	Poligon* noviPoli = (Poligon*)malloc(sizeof(Poligon));
	noviPoli->Vrh = (Tocka*)malloc(n * sizeof(Tocka));//arrow operator da dodemo do odredenog pointera unutar strukture
	noviPoli->n = n;//arrow operator da dodemo do odredenog pointera unutar strukture
	for (int i = 0; i < n; i++)
	{
		noviPoli->Vrh[i].x = niz_x[i]; // spremamo pozitivne koordinate
		noviPoli->Vrh[i].y = niz_y[i];
	}
	return noviPoli;
}
 
Tocka** pozitivni(Poligon* p, int* np) 
{
	int k=0;
	Tocka** novaCoorda= malloc(p->n * sizeof(Tocka*));//nova kordinata niz
	for (int i = 0; i < p->n; i++) { 
		if (p->Vrh[i].x > 0 && p->Vrh[i].y > 0) {//gledamo jesu obje koordinate pozitiivne
			novaCoorda[k] = &(p->Vrh[i]);//
			*np+=1;
			k++;
		}
	}
	return novaCoorda;

}