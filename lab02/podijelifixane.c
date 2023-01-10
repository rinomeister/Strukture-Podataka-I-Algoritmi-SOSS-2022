#include <stdio.h>
#include <stdlib.h>
int** podijeli(int*, int);
int main()
{
	int niz[] = { 1,2,3,4,5,1,2,3,4,5,6 };//stavljen ovako da lakse vidin podjelu
	int n = 11;//velicina niza
	//risit se viska malloca 10,11,12,13*cili main
	int** NoviNiz = malloc(2 * sizeof(int*));
	int prva_polovica = n / 2;
	int druga_polovica = n - prva_polovica;
	NoviNiz[0] = malloc(prva_polovica * sizeof(int));
	NoviNiz[1] = malloc(druga_polovica * sizeof(int));
 
	NoviNiz = podijeli(niz, n);
	printf("Novi nizovi su:\n");
	for (int i = 0; i < prva_polovica; i++)

	{
		printf("%d", NoviNiz[0][i]);
	}
	printf("\n");
	for (int i = 0; i < druga_polovica; i++)
	{
		printf("%d", NoviNiz[1][i]);
	}
	
	free(NoviNiz[0]);
	free(NoviNiz[1]);
	free(NoviNiz);
	return 0;
}
 
int** podijeli(int* niz, int n)
{
	int i, j;//za petlje
	int prva_polovica = n / 2;//prva polovica je cjelobrojno djeljenje 11/2=5
	int druga_polovica = n - prva_polovica;//druga polovica je 11-5 znaci 6
	int** NoviNiz = (int**)malloc(2 * sizeof(int*));//malloc za novi niz
	int* PrviNiz = (int*)malloc(prva_polovica * sizeof(int));//malloc za prvi dio niza
	int* DrugiNiz = (int*)malloc(druga_polovica * sizeof(int));//malloc za drugi dio niza
	for (i = 0; i < prva_polovica; i++)
		PrviNiz[i] = niz[i]; //prvi niz ide do prve polovice
	for (j = 0; j < druga_polovica; j++)
		DrugiNiz[j] = niz[j + i];//drugi niz ide od druge polovice zato se zbraja s j jer je i=prva polovica
	NoviNiz[0] = PrviNiz;
	NoviNiz[1] = DrugiNiz;
	return NoviNiz;
}