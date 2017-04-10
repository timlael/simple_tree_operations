/*
    Tim M. Lael
    CS4280
    p0
    13-FEB 2017
*/
/*
traversals.c
This is the source file containing function definitions for the tree
traversal and output printing/formatting functions.
*/
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "node.h"
#include "utils.h"
#include "buildtree.h"
#include "traversals.h"

/*
Void return type function which accepts a node_t and file base name as input.
This function serves as a wrapper for the Pre-order traversal walk and handles
output file naming and creation as well as file handle opening/closing.
*/
void preorder(node_t *root, char *outputBase){
  FILE *outpt;
  char *outExtension = ".preorder";
  char *outputFileName = malloc(snprintf(NULL, 0, "%s%s", outputBase, outExtension) + 1);
  sprintf(outputFileName, "%s%s", outputBase, outExtension);
  outpt = fopen(outputFileName, "w");
    if(outpt == NULL){
      fprintf(stderr, "Unable to open output file: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
  PRTW(root, outpt);
  fclose(outpt);
}

/* Similar purpose as preorder() above, only different traversal call */
void inorder(node_t *root, char *outputBase){
  FILE *outpt;
  char *outExtension = ".inorder";
  char *outputFileName = malloc(snprintf(NULL, 0, "%s%s", outputBase, outExtension) + 1);
  sprintf(outputFileName, "%s%s", outputBase, outExtension);
  outpt = fopen(outputFileName, "w");
    if(outpt == NULL){
      fprintf(stderr, "Unable to open output file: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
  IOTW(root, outpt);
  fclose(outpt);
}

/* Similar purpose as preorder() and inorder() above, only different traversal call */
void postorder(node_t *root, char *outputBase){
  FILE *outpt;
  char *outExtension = ".postorder";
  char *outputFileName = malloc(snprintf(NULL, 0, "%s%s", outputBase, outExtension) + 1);
  sprintf(outputFileName, "%s%s", outputBase, outExtension);
  outpt = fopen(outputFileName, "w");
  if(outpt == NULL){
    fprintf(stderr, "Unable to open output file: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  PSTW(root, outpt);
  fclose(outpt);
}

/*
Pre-Order Traversal Walk
Void return type function which accepts a node_t and a file pointer as input.
Recursive calls print formatted output to the file handle passed in.
*/
void PRTW(node_t *n, FILE *outpt){
  if (root == NULL){
    return;
  }
  fprintf(outpt,"%*s%-9s\n", n->depth*2,"", concat(n->string, n->id));
  if (n->l != NULL)
    PRTW(n->l, outpt);
  if (n->r != NULL)
    PRTW(n->r, outpt);
}

/*
In-order traversal Walk
Void return type function which accepts a node_t and a file pointer as input.
Recursive calls print formatted output to the file handle passed in.
*/
void IOTW(node_t *n, FILE *outpt){
  if (root == NULL){
    return;
  }
  if (n->l != NULL)
    IOTW(n->l, outpt);
    fprintf(outpt,"%*s%-9s\n", n->depth*2,"", concat(n->string, n->id));
  if (n->r != NULL)
    IOTW(n->r, outpt);
}

/*
Post-Order Traversal Walk
Void return type function which accepts a node_t and a file pointer as input.
Recursive calls print formatted output to the file handle passed in.
*/
void PSTW(node_t *n, FILE *outpt){
  if (root == NULL){
    return;
  }
  if (n->l != NULL)
    PSTW(n->l, outpt);
  if (n->r != NULL)
    PSTW(n->r, outpt);
    fprintf(outpt,"%*s%-9s\n", n->depth*2,"", concat(n->string, n->id));
}
