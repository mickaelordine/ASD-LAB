#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include "getfile.h"
#include "provapuntatorevoi.h"


void free_data(void **v, int size)
{
  for(int i = 0; i<size; i++)
  {
    free(v[i]);
  }
  free(v);
}


int cmp_int(const record *a, const record *b)
{
    return (a->field3)-(b->field3);
}

int cmp_float(const void *f, const void *s)
{
  record *a = (record*)f;
  record *b = (record*)s;
  if((a->field4)>(b->field4))
    return 1;
  else if((a->field4)<(b->field4))
    return -1;
  else
    return 0;
}

int cmp_string (const void * f, const void * s ) {
    record *a = (record*)f;
    record *b = (record*)s;
    //printf("%s %s", a->field2, b->field2);
    return strcmp(a->field2, b->field2);
}



//FUNZIONE PER LA VERIFICA DELL'ORDINAMENTO
int ordered(CMPFUNC compare, record **v, int size)
{
  int ord = -1;
  int i = 0;
  for(i = 0; i < size; i++)
  {
    ord = compare(v[i], v[i+1]);
	printf("%d,%s,%d,%f\n", v[i]->ID,v[i]->field2,v[i]->field3,v[i]->field4);
    if(ord > 0)
    {
      return i;
    }
  }
  if(ord>0)
    return i;
  return ord;
}

void print_records(record **v)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("<%s , %d , %f>\n", v[i]->field2, v[i]->field3, v[i]->field4);
    }
    printf("\n");
}


void insertionSort_int(record **v , int k){
	record **Array_MATRIX = (record**)malloc(sizeof(record*)*k);
	memcpy(&Array_MATRIX,&v,sizeof(v));
	time_t start=time(0);
	printf("adesso sono in insertionSort_int\n");
	insertionSort(Array_MATRIX,(CMPFUNC)cmp_int,0,k);
	time_t end = time(0);
	printf("Tempo impiegato per ordinare in %f \n", difftime(end,start));
	//printf("Sorted\n", ordered((CMPFUNC)cmp_int,Array_MATRIX,k));
	
}

void insertionSort_char(record **v , int k){
	record **Array_MATRIX = (record**)malloc(sizeof(record*)*k);
	memcpy(&Array_MATRIX,&v,sizeof(v));
	time_t start=time(0);
	printf("adesso sono in insertionSort_char\n");
	insertionSort(Array_MATRIX,(CMPFUNC)cmp_string,0,k);
	time_t end = time(0);
	printf("Tempo impiegato per ordinare in %f \n", difftime(end,start));
	printf("Sorted\n", ordered((CMPFUNC)cmp_string,Array_MATRIX,k));	
}

void insertionSort_float(record **v , int k){
	record **Array_MATRIX = (record**)malloc(sizeof(record*)*k);
	memcpy(&Array_MATRIX,&v,sizeof(v));
	time_t start=time(0);
	printf("adesso sono in insertionSort_float\n");
	insertionSort(Array_MATRIX,(CMPFUNC)cmp_float,0,k);
	time_t end = time(0);
	printf("Tempo impiegato per ordinare in %f \n", difftime(end,start));
	//printf("Sorted\n", ordered((CMPFUNC)cmp_float,Array_MATRIX,k));
}


void quickSort_int(record **v , int k){
	record **Array_MATRIX = (record**)malloc(sizeof(record*)*k);
	memcpy(&Array_MATRIX,&v,sizeof(v));
	time_t start=time(0);
	printf("adesso sono in quickSort_int\n");
	quick_sort(Array_MATRIX,(CMPFUNC)cmp_int,0,k);
	time_t end = time(0);
	printf("Tempo impiegato per ordinare in %f \n", difftime(end,start));
	//printf("Sorted\n", ordered((CMPFUNC)cmp_int,Array_MATRIX,k));	
}

void quickSort_char(record **v , int k){
	record **Array_MATRIX = (record**)malloc(sizeof(record*)*k);
	memcpy(&Array_MATRIX,&v,sizeof(v));
	time_t start=time(0);
	printf("adesso sono in quickSort_char\n");
	quick_sort(Array_MATRIX,(CMPFUNC)cmp_string,0,k);
	time_t end = time(0);
	printf("Tempo impiegato per ordinare in %f \n", difftime(end,start));
	printf("Sorted\n", ordered((CMPFUNC)cmp_string,Array_MATRIX,k));	
}

void quickSort_float(record **v , int k){
	record **Array_MATRIX = (record**)malloc(sizeof(record*)*k);
	memcpy(&Array_MATRIX,&v,sizeof(v));
	time_t start=time(0);
	printf("adesso sono in quickSort_float\n");
	quick_sort(Array_MATRIX,(CMPFUNC)cmp_float,0,k);
	time_t end = time(0);
	printf("Tempo impiegato per ordinare in %f \n", difftime(end,start));
	//printf("Sorted\n", ordered((CMPFUNC)cmp_float,Array_MATRIX,k));	
}


void choosen_algorithm(record** v,int x,int k){
	switch (x)
	{
	case 1: //Quick
		printf("Inizio ordinamento con Quick-sort\n");
		quickSort_int(v, k);
		quickSort_char(v, k);
		quickSort_float(v, k);
		break;

	case 2://binary-Insertion
		printf("Inizio ordinamento con Binary-Insertion\n");
		insertionSort_int(v, k);
		insertionSort_char(v, k);
		insertionSort_float(v, k);
		break;
	
	default:
		break;
	}
}



int main(int argc, char *argv[])
{
	int x=0;
	int k=0;
	printf("Specificare l'algoritmo da utilizzare: \n1.Quick-Sort\n2.Binary-Insertion Sort\n");
	scanf("%d", &x);
	while(x!=1 && x!=2){
		printf("Mi dispiace, il valore scelto non e' disponibile\n");
		printf("scegli un valore valido!\n");
		scanf("%d", &x);
	}
	k=K-1; //dimensione 

	clock_t start = time(0);
    record** v = (record**)malloc(sizeof(record*)*SIZE);
    v = (record**)loadfile("records.csv");
	choosen_algorithm(v,x,k);
	
	clock_t end = time(0);
	printf("tempo per riordinare l'intero file csv per tutti i metodi : %f", difftime(end,start));
	 free_data((void**)v, SIZE);
	return 0;
}