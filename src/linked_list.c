#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */


#include "linked_list.h"



/* functions to create lists */
node *make_node(int v, node *q) {
  node *p = malloc(sizeof(node));
  p->value = v;
  p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p) {
  node *q;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}

/* print list to console */
void print_list(node *p) {
  if (p != NULL) { //if current node isnt empty print value
    printf("|%d",p->value);
    if (p->next != NULL) { //if next node isnt empty print next value
      print_list(p->next);
    }
  }
}

int sum_squares(node *p) {
  //if current empty return 0, else retrun square of current + recur with next
  return (p == NULL) ? 0 : (p->value*p->value) + sum_squares(p->next);
}

typedef int (*fn_int_to_int)(int);

node *map(node *p, fn_int_to_int f) { 
  return (p == NULL) ? NULL : make_node(f(p->value), map(p->next,f));
}

int square(int x) { return x * x; }

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }

