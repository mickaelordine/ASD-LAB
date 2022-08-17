#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include "getfile.h"
#include "provapuntatorevoi.h"




//protipi
void insertionSort(record **Array_PTR,CMPFUNC compare,int l ,int k);
void **sorted_array_sort(void **array, CMPFUNC compare, int size,int algorithm);
void partition (record **arr, CMPFUNC compare, int low, int high, int *l, int *r);
void quick_sort(record **arr, CMPFUNC compare, int low, int high);



void swap(record **v, int i, int j)
{
    void *tmp;
    tmp=v[i];
    v[i]=v[j];
    v[j]=tmp;
}

int binarySearch(record **Array_PTR,record *selected,CMPFUNC compare,int low, int high){

if(high<=low)
	return (compare(selected,Array_PTR[low]))<0 ? low : low+1;
  
	int mid = (low+high)/2;

	if(compare(selected, Array_PTR[mid])==0){
		return mid +1;
	}else if (compare(selected,Array_PTR[mid])>0){
		 return binarySearch(Array_PTR,selected,compare,mid+1,high);
	}else{
		return binarySearch(Array_PTR,selected,compare,low,mid-1);
	}

} 


// Function to sort an array a[] of size 'k'
//k è un valore che scegliamo noi, da dopo quello inizia il merge con
//i suoi due sub array, di cui questo Binaryinsert sort è il primo 'L[]'

void insertionSort(record **Array_PTR,CMPFUNC compare,int l ,int r){
int i,j,loc;
record * selected;

for(i= l; i<=r; ++i){
		j=i-1;

		selected=Array_PTR[i];

		loc = binarySearch(Array_PTR, selected,compare, l, j);
	  
		while(j>=loc){
			Array_PTR[j+1]= Array_PTR[j];
			j--;
		}

		Array_PTR[j+1] = selected;
}
}

/*return a random position for the random pivot*/
int random(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}



void partition(record **arr, CMPFUNC compare, int low, int high, int *l, int *r)
{
  void *pivot = arr[random(low,high)];//random
  //void *pivot = arr[high];//high || low
  //int mid = (high+low)/2;
  //void *pivot = arr[mid];//mid
  *l = low;
  *r = low;
  int u = high;
  while(*r <= u)
  {
    if(compare(arr[(*r)], pivot)<0)
    {
      swap(arr, *l, *r);
      (*l)++;
      (*r)++;
    }
    else if(compare(arr[(*r)], pivot)>0)
    {
      swap(arr, *r, u);
      u--;
    }
    else
    {
      (*r)++;
    }
  }
}

void quick_sort(record **arr, CMPFUNC compare, int low, int high)
{
    if (low < high)
    {
        int l;
        int r;
        partition(arr, compare, low, high, &l, &r);
        quick_sort(arr, compare, low, l-1);
        quick_sort(arr, compare, r, high);
    }
}


// It return the pointer to the generic array sorted
void **sorted_array_sort(void **array, CMPFUNC compare, int size,int algorithm)
{
    if (compare == NULL)
    {
        fprintf(stderr, "sorted_array_sort: comparator parameter cannot be NULL");
        exit(EXIT_FAILURE);
    }

    if (array == NULL)
    {
        fprintf(stderr, "sorted_array-sort: array parameter cannot be NULL");
        exit(EXIT_FAILURE);
    }

    if (size <= 0)
    {
        fprintf(stderr, "sorted_array-sort: size parameter cannot be zero or negative");
        exit(EXIT_FAILURE);
    }

    //algorithm = 0 -> quick
    //algorithm !=0 -> binary-insertion Sort
    if(algorithm == 0){
      quick_sort((record**)array, compare, 0, size - 1);
    }else{
      insertionSort((record**)array, compare, 0, size -1);
    }

    
    return (void **)array;
}