#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* podniz(int* niz, int start, int stop);
int main()
{
    int niz[] = { 0,1,2,3,4,5,6,7,8 };
    int start = 3;//od ovog indeksa pocinje podniz
    int stop = 8;//do ovog indeksa traje podniz
    int* subarray = podniz(niz, start, stop);//poziv funckije
    int subarraylength = stop - start;//podniz ce imati elemenata = stop-start jer su mu to krajna i poccetna tocka
    for (int i = 0; i < subarraylength; i++)
    {
        printf("%d\n", subarray[i]);//printanje podniza
    }
    return 0;
}
int* podniz(int* niz, int start, int stop)
{
    int i = 0;
    int* noviNiz = (int*)malloc((stop - start) * sizeof(int));//dinamicka alokacija novog niza koji ce spremati filtrirane brojeve
    while (start < stop)
    {
        noviNiz[i] = niz[start];
        start++;
        i++;
    }
    return noviNiz;

}