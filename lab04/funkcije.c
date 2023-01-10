#include "Vjezba3.h"

int* generiraj(int n)
{
	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = rand() % 5;
	for (int i = 1; i < n; i++)
	{
		niz[i] = niz[i - 1] + rand() % 5 + 1;
	}
	return niz;
}

void shuffle(int* niz, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = (rand() * rand()) % n;
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}
//•	presjek(skupA, skupB) – funkcija računa presjek dva skupa
//Za dužinu (alociranje) niza koji će sadržati presjek nizova se može uzeti veća dužina od dva primljena niza. 
//Nizove koji predstavljaju skupove alocirati i oslobađati za svako mjerenje. 
int* presjek(int* skupA, int* skupB, int min, int max)
{
	int i, j;//za petlje
	int k = 0;// za skup aib
	int* skupAiB = (int*)malloc(sizeof(int) * max);//niz za presjek
	for (i = 0;i < min;i++)//do prvog mina
	{
		for (j = 0;j < max;j++)
		{
			if (skupA[i] == skupB[j])//ako su indexi oba niza jednaki onda se spremaju u index skupAiB
			{
				skupAiB[k] = skupA[i];
				k++;
			}
		}
	}
	return skupAiB;
}
//cmp funkcija za bsearch
int cmp(int* a, int* b)
{
	return ((*a) - (*b));
}

int* presjek_sortiran(int* skupA, int* skupB, int min, int max)
{
	int j = 0;
	qsort(skupB, max, sizeof(int), cmp);// sortiranje niza prije ulaska u bsearch
	int* sortirani_skupAiB = (int*)malloc(sizeof(int) * max);

	for (int i = 0; i < min; i++)
	{
		if ((int*)bsearch(&skupA[i], skupB, max, sizeof(int), cmp))
		{
			sortirani_skupAiB[j] = skupA[i];
		}
	}
	return sortirani_skupAiB;
}

int* presjek_quicksort(int* skupA, int* skupB, int min, int max)
{
	int* quicksortirani_skupAiB = (int*)malloc(sizeof(int) * max);
	qsort(skupB, max, sizeof(int), cmp);
	for (int i = 0;i < min;i++)
	{
		for (int j = 0;j < max;j++)
		{
			if (skupA[i] == skupB[j])
				quicksortirani_skupAiB[i] = skupA[i];
		}
	}
	return quicksortirani_skupAiB;
}