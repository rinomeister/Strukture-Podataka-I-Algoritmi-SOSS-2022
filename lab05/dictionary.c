#include "dictionary.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

Dictionary create()
{
	Word* newDict = (Word*)malloc(sizeof(Word));//alocira novi dictionary tipa word
	newDict->word = "";//word da stavlja da je nista jer nema nijedne rijeci
	newDict->count = 0;//brojac je nula - pojavlja se 0 puta
	newDict->next = NULL;// koja pkkazuje na iduci element
	return newDict;
}

void add(Dictionary dict, char *str)
{
	Dictionary temp = dict;//kreiram temp dictionary
	while (temp != NULL)//ako postoji element 
	{
		if (strcmp(str, temp->word) == 0)//usporeduje dva stringa ako su jednaki count se povecava za 1
		{
			temp->count += 1;
			break;
		}

		else if (temp->next == NULL)//ako je samo jedan element u listi,pa radimo nvou samo za novi element
		{
			Dictionary novi = (Dictionary)malloc(sizeof(Word));//inicijalizira se memorija za
			novi->word = (char*)malloc(sizeof(char)* strlen(str) + 1);//inicijliazira se word za novu rijec
			novi->word = strcpy(novi->word, str);//kopira se rijec
			novi->count = 1;
			novi->next = NULL;//maknemo next za iduci //govori da je zadnji element u nizu
			temp->next = novi;//maknemo temp na novi
			break;
		}

		else if ((strcmp(str, temp->word) > 0) && (strcmp(str, temp->next->word) < 0))//ako je string od trenutacne riejci veci od 0(po abecednom)
																					// i ako je string manji od iduce rijeci
		{
			Dictionary novi = (Dictionary)malloc(sizeof(Word));//alokacija za novu listu
			novi->word = (char*)malloc(sizeof(char)* strlen(str) + 1);//alokacija za novu rijec
			novi->word = strcpy(novi->word, str);
			novi->count = 1;
			novi->next = temp->next;
			temp->next = novi;
			break;
		}


		temp = temp->next;//idemo dalje po listi//zamjena za i++
	}
}

void print(Dictionary dict)
{
	Dictionary temp = dict;
	while (temp != NULL)
	{
		printf("%s \n %d\n", temp->word, temp->count);
		temp = temp->next;//idemo dalje po listi
	}
}

void destroy(Dictionary dict)
{
	//trebaju nam dva pointera jer trebamo oslobodit trenutnu i iducu
	Dictionary temp = dict->next;//nemozemo brisat glavu zato idemo naprid
	Dictionary temp2;
	free(dict);
	while (temp != NULL)//idemo kroz listu stavljam pointere i oslobadam pointere
	{
		temp2 = temp;//za korake i za freeeanje
		temp = temp->next;
		free(temp2->word);
		free(temp2);
	}
}
Dictionary filterDictionary(Dictionary indict, int (*filter)(Word *w))
{
	Dictionary tmp = indict;

	while (tmp->next != NULL) { //letim kroz temp do zadnjeg elementa
		if (filter(tmp->next)) //akoe filter prosa ide dalje
		{
			tmp = tmp->next;
		}
		else //kreiram novu temp varijablue selim na iduci i brism ovaj
		
		{
			Dictionary tmp1 = tmp->next;
			tmp->next = tmp1->next;
			free(tmp1);
		}
	}

	return indict;
}

int filter(Word *w)
{
	if ((w->count >= 5) && (w->count <= 10) && (strlen(w->word) > 3))
	{
		return 1;
	}
	else
		return 0;
}


