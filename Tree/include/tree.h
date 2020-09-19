#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
  char data;
  struct Node *left;
  struct Node *right;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node *new_node(char data);

/* Prototypes for utility functions */
int search(char arr[], int strt, int end, char value);

void print_postorder(struct Node *node);

struct Node *build_tree(char in[], char pre[], int in_left, int in_right,
                        int pre_left, int pre_right);

struct Node *build_tree_static(char in[], char pre[], int in_left, int in_right,
                               int pre_left, int pre_right);

void build_tree_string(char in[], char pre[], char *output);

#endif