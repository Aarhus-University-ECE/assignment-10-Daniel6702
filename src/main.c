#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "btree.c"
#include "linked_list.c"


// File for sandboxing and trying out code
int main(void) {
  // Add your code
  
  node *ns = make_node(1, make_node(2, make_node(3, make_node(4, make_node(5, NULL)))));
  print_list(ns);
  int sum = sum_squares(ns);
  printf("\n%d\n",sum);

  int (*sf)(int);
  sf = square;
  ns = map(ns,sf);
  print_list(ns);
  printf("\n\n");

  //btree tests
  test1();
  test2();
  test3();
  test4();
  test5();
  

  struct tree_node *root = Initialize(NULL);
  root = Initialize(root);
  root = Insert(20, root);
  root = Insert(5, root);
  root = Insert(1, root);
  root = Insert(15, root);
  root = Insert(9, root);
  root = Insert(7, root);
  root = Insert(12, root);
  root = Insert(30, root);
  root = Insert(25, root);
  root = Insert(40, root);
  root = Insert(45, root);
  root = Insert(42, root);
  print_tree(root);
  printf("\n%d",Contains(20,root));
  printf("\n%d",Contains(5,root));
  printf("\n%d",Contains(1,root));
  printf("\n%d",Contains(15,root));
  printf("\n%d",Contains(9,root));
  printf("\n%d",Contains(7,root));
  printf("\n%d",Contains(12,root));
  printf("\n%d",Contains(30,root));
  printf("\n%d",Contains(25,root));
  printf("\n%d",Contains(40,root));
  printf("\n%d",Contains(45,root));
  printf("\n%d",Contains(42,root));
  return 0;
}