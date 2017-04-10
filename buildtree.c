/*
    Tim M. Lael
    CS4280
    p0
    13-FEB 2017
*/
/*
buildtree.c
This is the source file containing function definitions for the tree
building and node placement functions.
The global root node_t is defined within.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "utils.h"
#include "buildtree.h"


/* Temporary node_t definition */
node_t *temp;
/* Global root node_t definition */
node_t *root;

/*
Tree building function which accepts a file pointer and has a void return type.
The root pointer is set to NULL to indicate an empty tree, then the tempSpace
file is accessed through the passed file pointer. Lines are then read one at a
time (while they exist) and memory is allocated for temporary nodes and values
are assigned to their appropriate positions within those nodes. Temp nodes are
then placed using the findPlace() function.
*/
void buildTree(FILE *tempFile){
  root = NULL;
  char line[255];
  while (fscanf(tempFile, " %s[^ \t\n]", line) == 1){
    temp = malloc(sizeof(node_t));
    temp->l = temp->r = NULL;
    sprintf(temp->id, "%.1s",line);
    strcpy(temp->string, line);
    temp->depth = 0;

    /* place first incoming temp node as root */
    if(root == NULL){
      root = temp;
    }
    else{
      findPlace(root);
    }
  }
}

/*
Void return type function which accepts a node_t input to properly place all nodes
other than root. The input is the node at which the search begins (normally the root)
and recursion allows the search to continue through the tree until a suitable parent
is found for the child.
*/
void findPlace(node_t *searchNode){
  /*
  if temp->id equals searchNode id, add string to the front
  of searchNode->string. This is duplicate id handler
  */
  if (strcmp(temp->id, searchNode->id) == 0){
    strcpy(searchNode->string, concat(searchNode->string, temp->string));
  }
  /* Branch to right if temp->id is larger than searchNode->id */
  else if ((strcmp(temp->id, searchNode->id) > 0) && (searchNode->r != NULL)){
    temp->depth++;
    findPlace(searchNode->r);
  }
  /* Place temp node in first appropriate NULL right position */
  else if ((strcmp(temp->id, searchNode->id) > 0) && (searchNode->r == NULL)){
    temp->depth++;
    searchNode->r = temp;
  }
  /* Branch to left if temp->id is smaller than searchNode->id */
  else if ((strcmp(temp->id, searchNode->id) < 0) && (searchNode->l != NULL)){
    temp->depth++;
    findPlace(searchNode->l);
  }
  /* Place temp node in first appropriate NULL left position */
  else if ((strcmp(temp->id, searchNode->id) < 0) && (searchNode->l == NULL)){
    temp->depth++;
    searchNode->l = temp;
  }
}
