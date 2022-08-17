#ifndef ASD

//typedef struct _Record record;

//puntatore a funzione compare che ritorna un int
typedef int (*CMPFUNC)(const void*, const void*);

typedef struct _Record {
	int ID;
	char *field2;
	int field3;
	float field4;
}record;

#define SIZE 20000000 //20 milioni
#define K 6
#define SIZEmezzi 1000000
#define SIZEBINARY 1000000
#define BINARY 1
#define QUICK 0

//compare
int cmp_float(const void *f, const void *s);
int cmp_string (const void * f, const void * s );
int cmp_int(const record *a, const record *b);


int compare(void*P1,void*P2,int relational);
void swap(record **v, int i, int j);
void **sorted_array_sort(void **array, CMPFUNC compare, int size,int algorithm);
void quick_sort(record **arr, CMPFUNC compare, int low, int high);
void partition(record **arr, CMPFUNC compare, int low, int high, int *l, int *r);
int binarySearch(record **Array_PTR,record* selected,CMPFUNC compare,int low, int high);
void insertionSort(record **Array_PTR,CMPFUNC compare,int l ,int k);
int is_sorted(void** arr,int end, CMPFUNC comp);


#endif //LABORATORIO_ALGORITMI_2020_21_SORTS_H