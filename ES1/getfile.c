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


























/*int main(int argc, char *argv[])
{
    bool flag = true;
    if (argc == 1) {
        fprintf(stderr, "Nome del file da leggere: \n");
        exit(1);
    }
    
    //carico i file in una struttura dati
    int length = 0;
    char **words = loadfile(argv[1], &length);
    if(flag){
    for(int i = 0; words[i] != NULL; i++)
    {
        printf("%s\n", words[i]);
    }
    }
    printf("Fatto\n");
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("tempo impiegato %f\n", time_spent);
}*/

/*
char **loadfile(char *filename, int *length)
{
    start = clock();
    FILE *f = fopen("records.csv", "r");
    if(!f)
    {
        fprintf(stderr, "Errore: il file non può essere aperto per la lettura\n");
        return NULL;
    }

    int arrlen = STEPSIZE;
    
        //spazio allocato per 100
    char **lines = (char **)malloc(arrlen * sizeof(char*));
    
    char buf[1000];
    int i = 0;
    while(fgets(buf, 1000, f))
    {
        //controlla che l'array sia pieno. se lo è, si estende
        if(i == arrlen)
        {
            arrlen += STEPSIZE;
            
            char ** newlines = realloc(lines, arrlen * sizeof(char*));
            if(!newlines)
            {
                fprintf(stderr, "Non si può riaccolare\n");
                exit(1);
            }
            lines = newlines;
        }
        
        //carattere di nuova riga
        buf[strlen(buf) -1] = '\0';
        
        //lunghezza del buf
        int slen = strlen(buf);
        
        char *str = (char *)malloc((slen +1) * sizeof(char));

        //copia le stringhe da buf a str
        strcpy(str, buf);
        
        //allega str alla struttura dati
        lines[i] = str;
        
        i++;
    }

    int len = i; //imposta la lunghezza dell'array di char
    return lines;
}

*/











