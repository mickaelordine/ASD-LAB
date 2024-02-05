#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>
#include "getfile.h"
#include "provapuntatorevoi.h"

clock_t start;
clock_t end;


void **loadfile(char * filename);


int LENGTH = SIZE;
#define MAX_BUF_LEN 1024

void **loadfile(char *f)
{
  void** r = (void*)malloc(sizeof(record)*LENGTH);
  printf("Array created\n");
  int ID;
  char f2[1024];
  int f3;
  float f4; 
  int elements=0;
  FILE* file;
  file  = fopen("records.csv", "r");
  if (!file) {
        printf("Can't open file\n");
        return 0;
    }
    printf("Loading records\n");
    time_t start = time(0);
    int i = 0;
    while(!feof(file) && i < LENGTH){
      record* rec = (record*) malloc(sizeof(record));
      //printf("sto stampando");
      int n = fscanf(file, "%d,%[^,],%d,%f", &ID, f2, &f3, &f4);
      if(n != 4) {
            if(feof(file)) {
                continue;
            }
            printf("Error while reading file at line %d", elements);
            exit(5);
        }
      rec -> ID = ID;
      rec -> field2 = strdup(f2);
      rec -> field3 = f3;
      rec -> field4 = f4;
      r[elements] = rec;
      elements++;
      i++;
      }
    
    printf("File loaded. Closing file\n");
    fclose(file);
    time_t end = time(0);
    printf("%f\n", difftime(end, start));
    return r;
}
