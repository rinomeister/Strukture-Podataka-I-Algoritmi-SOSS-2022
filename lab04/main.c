#include "Vjezba3.h"

int main()
{
	srand(time(NULL));
	int min = 10000;
	int max = 50000;
	int start;
	int stop;
	int* skupA = generiraj(min);
	int* skupB = generiraj(max);
	shuffle(skupA, min);
	shuffle(skupB, max);
	int* skupAiB;
	int* sortirani_skupAiB;
	int* quicksortirani_skupAiB;

	// ****** PRESJEK DVA NESORTIRANA NIZA *******
	min = 10000;
	max = 50000;
	for (min;min <= max;min += 5000)
	{
		start = clock();
		skupAiB = presjek(skupA, skupB, min, max);
		stop = clock();
		printf("Za duzinu skupa A sa 10000 elemenata do 50000 i skupa B sa 50000 vrijeme izracuna presjeka dvaju nesortirana niza je: %ds\n", (stop - start) / CLOCKS_PER_SEC);
	}

	start = clock();
	skupAiB = presjek(skupA, skupB, min, max);
	stop = clock();
	printf("Za duzinu skupa A sa 10000 elemenata i duzinu skupa B sa 50000 elemenata vrijeme izracuna presjeka dvaju nesortirana niza je: %ds\n", (stop - start) / CLOCKS_PER_SEC);

	max = 100000;
	start = clock();
	skupAiB = presjek(skupA, skupB, min, max);
	stop = clock();
	printf("Za duzinu skupa A sa 10000 elemenata i duzinu skupa B sa 100000 elemenata vrijeme izracuna presjeka dvaju nesortirana niza je: %ds\n", (stop - start) / CLOCKS_PER_SEC);

	min = 50000;
	max = 100000;
	start = clock();
	skupAiB = presjek(skupA, skupB, min, max);
	stop = clock();
	printf("Za duzinu skupa A sa 50000 elemenata i duzinu skupa B sa 100000 elemenata vrijeme izracuna presjeka dvaju nesortirana niza je: %ds\n", (stop - start) / CLOCKS_PER_SEC);

	// ******** PRESJEK NESORTIRANOG I SORTIRANOG NIZA *******
	min = 10000;
	max = 50000;
	for (min;min <= max;min += 5000)
	{
		start = clock();
		sortirani_skupAiB = presjek_sortiran(skupA, skupB, min, max);
		stop = clock();
		printf("Za duzinu skupa A sa 10000 elemenata do 50000 i skupa B sa 50000 vrijeme izracuna presjeka nesortiranog i sortiranog niza je: %ds\n", (stop - start) / CLOCKS_PER_SEC);
	}
	min = 10000;
	max = 50000;
	start = clock();
	sortirani_skupAiB = presjek_sortiran(skupA, skupB, min, max);
	stop = clock();
	printf("Za duzinu skupa A sa 10000 elemenata i duzinu skupa B sa 50000 elemenata vrijeme izracuna presjeka nesortiranog i sortiranog niza je: %ds\n", (stop - start) / CLOCKS_PER_SEC);

	max = 100000;
	start = clock();
	sortirani_skupAiB = presjek_sortiran(skupA, skupB, min, max);
	stop = clock();
	printf("Za duzinu skupa A sa 10000 elemenata i duzinu skupa B sa 100000 elemenata vrijeme izracuna presjeka nesortiranog i sortiranog niza je: %ds\n", (stop - start) / CLOCKS_PER_SEC);

	min = 50000;
	max = 100000;
	start = clock();
	sortirani_skupAiB = presjek_sortiran(skupA, skupB, min, max);
	stop = clock();
	printf("Za duzinu skupa A sa 50000 elemenata i duzinu skupa B sa 100000 elemenata vrijeme izracuna presjeka nesortiranog i sortiranog niza je: %ds\n", (stop - start) / CLOCKS_PER_SEC);


	// ******** PRESJEK NESORTIRANOG I SORTIRANOG NIZA SA QSORT ********
	min = 10000;
	max = 50000;
	for (min;min <= max;min += 5000)
	{
		start = clock();
		quicksortirani_skupAiB = presjek_quicksort(skupA, skupB, min, max);
		stop = clock();
		printf("Za duzinu skupa A sa 10000 elemenata do 50000 i skupa B sa 50000 vrijeme izracuna presjeka nesortiranog i sortirnaog niza sa quicksort je: %ds\n", (stop - start) / CLOCKS_PER_SEC);
	}
	min = 10000;
	max = 50000;
	start = clock();
	quicksortirani_skupAiB = presjek_quicksort(skupA, skupB, min, max);
	stop = clock();
	printf("Za duzinu skupa A sa 10000 elemenata i duzinu skupa B sa 50000 elemenata vrijeme izracuna presjeka nesortiranog i sortiranog niza sa quicksort je: %ds\n", (stop - start) / CLOCKS_PER_SEC);

	max = 100000;
	start = clock();
	quicksortirani_skupAiB = presjek_quicksort(skupA, skupB, min, max);
	stop = clock();
	printf("Za duzinu skupa A sa 10000 elemenata i duzinu skupa B sa 100000 elemenata vrijeme izracuna presjeka nesortiranog i sortiranog niza sa quicksort je: %ds\n", (stop - start) / CLOCKS_PER_SEC);

	min = 50000;
	max = 100000;
	start = clock();
	quicksortirani_skupAiB = presjek_quicksort(skupA, skupB, min, max);
	stop = clock();
	printf("Za duzinu skupa A sa 50000 elemenata i duzinu skupa B sa 100000 elemenata vrijeme izracuna presjeka nesortiranog i sortiranog niza sa quicksort je: %ds\n", (stop - start) / CLOCKS_PER_SEC);
	return 0;
}