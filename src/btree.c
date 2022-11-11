#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int Empty(struct tree_node *t) {
  // Test if empty
  if (t == NULL) {
    return 1;
  } else {
    return 0;
  }
}

struct tree_node *createNode(int value)
{
  struct tree_node *node = (struct tree_node*)malloc(sizeof(struct tree_node));
  node->item = value;
  node->right = node->left = NULL;
  return node;
}

struct tree_node *Insert(int x, struct tree_node *t) {
  if (Empty(t)) {
    return createNode(x);
  } 
  if (x <= t->item) {
    t->left = Insert(x,t->left);
  } else if (x > t->item) {
    t->right = Insert(x,t->right);
  }
  
  return t;
}

struct tree_node *Remove(int x, struct tree_node *t) {
  if (Empty(t)==1) {
    return t;
  }
  if (x < t->item) {
    t->left = Remove(x,t->left);
  } else if (x > t->item) {
    t->right = Remove(x,t->right);
  } else {
    if (t->left == NULL) {
      return t->right;
    } else if (t->right == NULL) {
      return t->left;
    }
    int data = t->right->item;
    struct tree_node *temp = t->right;
    while (temp->left != NULL) {
        data = temp->left->item;
        temp = temp->left;
    }    
    t->right = Remove( data,t->right);
  }
  return t;
}

int Contains(int x, struct tree_node *t) {
  /*
  if (t!=NULL);
  if (x == t->item)  {return 1;}
  return ((x <= t->item && Contains(x,t->left)) ? 1 : 0);
  return ((x >= t->item && Contains(x,t->right)) ? 1 : 0);
  */
 if (t == NULL) {
  return 0;
 }
 if (x == t->item) {
  return 1;
 }
 if (x < t->item) {
  return Contains(x,t->left);
 }
 if (x> t->item) {
  return Contains(x,t->right);
 }
}




struct tree_node *Initialize(struct tree_node *t) {
  return t;
}


int Full(struct tree_node *t) {
  // Test if full
  return 1;
}


void print_tree(struct tree_node* root)
{
    if (root != NULL) {
        print_tree(root->left);
        printf("|%d", root->item);
        print_tree(root->right);
    }
}

void test1(void) {
  struct tree_node *root = Initialize(NULL);

  if (Empty(root)) {
    printf("Test 1 Succeeded\n");
  } else {
    printf("Test 1 Failed\n");
  }

}

void test2(void) {
  struct tree_node *root = Initialize(NULL);

  root = Insert(50,root);
  root = Remove(50,root);

  if (Empty(root)) {
    printf("Test 2 Succeeded\n");
  } else {
    printf("Test 2 Failed\n");
  }

}

void test3(void) {
  struct tree_node *root = Initialize(NULL);

  int x = 50;
  root = Insert(x,root);
  int y = Contains(x,root);

  if (y==1) {
    printf("Test 3 Succeeded\n");
  } else {
    printf("Test 3 Failed\n");
  }

}

void test4(void) {
  struct tree_node *root = Initialize(NULL);

  int x = 50;
  int y = 30;
  root = Insert(x,root);
  root = Insert(y,root);
  root = Remove(x,root);
  int z = Contains(y,root);

  if (z==1) {
    printf("Test 4 Succeeded\n");
  } else {
    printf("Test 4 Failed\n");
  }

}

void test5(void) {
  struct tree_node *root = Initialize(NULL);

  int x = 50;
  root = Insert(x,root);
  root = Insert(x,root);
  root = Remove(x,root);
  int y = Contains(x,root);
  root = Remove(x,root);
  int z = Contains(x,root);

  if (y==1 && z == 0) {
    printf("Test 5 Succeeded\n");
  } else {
    printf("Test 5 Failed\n");
  }

}