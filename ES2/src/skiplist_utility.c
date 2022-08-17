#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "skiplist_utility.h"

struct _node {
  node** next;
  unsigned int size;
  void* item;
};

struct _skiplist {
  node *head;
  unsigned int max_level;
  int (*compare)(const void*, const void*);
};

static double random() { 
    return (double)rand() / (double)((unsigned)RAND_MAX + 1); 
  }

static unsigned int random_level() {
  unsigned int lvl = 1;
  while(random() < 0.5 && lvl < MAX_HEIGHT)
    lvl++;
  return lvl;
}

/* allocating memory for a new skiplist and settinig the compare */
skiplist* skiplist_new(int (*comp)(const void*, const void*)) {
  skiplist* list = (skiplist*) malloc(sizeof(skiplist)); 
  list->compare = comp;
  list->max_level = (MAX_HEIGHT + 1); 
  node* x = (node*) malloc(sizeof(node));
  list->head = x;
  x->size = (MAX_HEIGHT + 1); 
  x->next = (node**) malloc(x->size*sizeof(node*)); 
  for(unsigned int i = 0;i < x->size;i++) {
    x->next[i] = NULL;
  }
  return list;
}

/* dealloc mem with free() */
void skiplist_free(skiplist* list) {
  for(unsigned int i = 0;i < list->max_level;i++)
    free(list->head->next[i]); 
  free(list->head);
  free(list); 
}

void skiplist_insert(skiplist* list,void* l) {
  node* new = (node*) malloc(sizeof(node));
  new->size = (random_level() + 1);
  new->item = l;
  new->next = (node**) malloc(new->size*sizeof(node*));
  for(unsigned int i = 0;i < new->size;i++)
    new->next[i] = NULL;
  if(new->size > list->max_level) {
    skiplist* tmp = malloc(sizeof(skiplist));
    list->max_level = new->size;
    tmp->head->next = realloc(list->head->next,list->max_level*sizeof(node*));
    if(tmp == NULL) {
      printf("Error!");
      exit(EXIT_FAILURE);
    }
    list = tmp;
  }
  node* x = list->head;
  for(unsigned int k = list->max_level-1;k >= 1; k--) {
    if((void*) x->next[k] == NULL || list->compare(new->item,x->next[k]->item) < 0) { //se il secondo è maggiore del primo
      if(k < new->size) {
        new->next[k] = x->next[k]; //ordiniamo in maniera crescente la skiplist
        x->next[k] = new; 
      }
    }
    else {
      x = x->next[k]; //andiamo avanti 
      k++; //senza scendere di livello
    }
  }
}

/* searching while l is bigger than the items in the list */
void* skiplist_search(skiplist* list,void* l) {
  node* x = list->head;
  // loop invariant: x->item < l
  for(unsigned int i = list->max_level - 1;i >= 1;i--) {
    while(x->next[i] && list->compare(x->next[i]->item,l) < 0) 
      x = x->next[i];
  }
  // x->item < l <= x->next[1]->item
  x = x->next[1];
  if(list->compare(x->item,l) == 0) { //se l'hai trovato ritorna la parola altrimenti NULL
    return x->item;
  }
  return NULL;
}

/* checking all the first levels are ordered */
int skiplist_is_ordered(skiplist* list) {
  node* x = list->head;
  for(;x->next[1]->next[1] != NULL;x = x->next[1]) {
    printf("%s level %d \n",(char*)x->next[1]->item, (int)x->size);
    if(list->compare(x->next[1]->item,x->next[1]->next[1]->item) > 0)
      return 0;
  }
  return 1;
}