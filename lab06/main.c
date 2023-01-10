#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
	void* ignore;
	int priority;
}Element;

typedef struct {
	Element* array;
}Queue; // struct koji sadrzi struct

int length = 10; //duzina

void printQueue(Queue* q) { //printa sve u nizu
	for (int i = 0; i < length; i++) {
		printf("%d\n", q->array[i].priority);
	}
}

// funkcija koja binarnu gomilu popravlja "prema gore"
// za gomilu q, ako je zadnje dodani element veci od roditelja, zamijeni ih
// to se ponavlja rekurzivno dko zadnje uneseni broj ne legne na svoje misto u gomili
void fixTop(Queue* q, int number) {
	if (number == 0) { //uvjet za izlazak iz rekurzije
		return;
	}
	else {
		int roditelj = floor((number - 1) / 2); //formula za pronalazak indeksa od parent elementa
		Element roditeljElement = q->array[roditelj];

		if (roditeljElement.priority < q->array[number].priority) { // if roditelj manji od novog zamijeni ih
			Element tmp = q->array[roditelj];//swap
			q->array[roditelj] = q->array[number];
			q->array[number] = tmp;
			fixTop(q, roditelj); // rekurzivni poziv
		}
	}
}

//funkcija popravlja gomilu "prema dole"
//nadjemo index livog i desnog djeteta i usporedim ih sa roditeljem
//ako je roditelj manji od nekog od djece zamijenimo ih
//to se ponavlja rekurzivno dok ne dodjemo do kraja gomile ili dok nema djece koja su manja od roditelja
void fixBottom(Queue* q, int number) {
	int left = 2 * number + 1; //racuna index donjeg livog u gomili
	int right = 2 * number + 2;//racuna index donjeg desnog u gomili

	if (right >= length && left >= length) { //ako in je index veci ili jednak duzini niza to znaci da ne postoje
		return;
	}

	if (left < q->array && right < q->array) {
		if (q->array[number].priority < q->array[left].priority && q->array[left].priority >= q->array[right].priority) { //ako je roditelj manji od livog onda ih zamini
			Element tmp = q->array[number];//swap
			q->array[number] = q->array[left];
			q->array[left] = tmp;
			fixBottom(q, left);
		}
		else if (q->array[number].priority < q->array[right].priority && q->array[right].priority >= q->array[left].priority) { //ako je roditelj manji od desnog onda ih zamini
			Element tmp = q->array[number];
			q->array[number] = q->array[right];
			q->array[right] = tmp;
			fixBottom(q, right);
		}
	}
	else if (left < q->array && q->array[left].priority > q->array[right].priority) { //ako je roditelj manji od livog onda ih zamini
		Element tmp = q->array[number];
		q->array[number] = q->array[left];
		q->array[left] = tmp;
		fixBottom(q, left);
	}

}

void add(Queue* q, int number) {
	q->array[number].priority = number; // na index number kao prioritet dodaj number
	fixTop(q, number); // popravi gomilu prema gore
}

void popBack(Queue* q) { //funkcija izbaci element s vrha gomile tako da ga zamijeni sa zadnjim i onda popravlja gomilu "prema dole"
	q->array[0] = q->array[length - 1];
	length -= 1;

	q->array = (Element*)realloc(q->array, length * sizeof(Element)); //niz se realocira jer je sad kraci za jedan element
	fixBottom(q, 0);
}

int main() {
	Queue* q = (Queue*)malloc(sizeof(Queue)); // alocira memoriju velicine jednog Queue
	q->array = (Element*)malloc(length * sizeof(Element)); //alocira memoriju za jedna Element u nizu Elemenata u Queue 

	for (int i = 0; i < length; i++) {
		add(q, i);
	}

	printf("Citava, fiksana lista\n");
	printQueue(q);
	printf("\n\n");
	printf("Lista nakon popBack() #1\n");
	popBack(q);
	printQueue(q);
	printf("\n\n");
	printf("Lista nakon popBack() #2\n");
	popBack(q);
	printQueue(q);
	free(q);

}