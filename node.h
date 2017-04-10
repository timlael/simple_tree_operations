/*
    Tim M. Lael
    CS4280
    p0
*/

/*
node.h
This file is the header file which contains the
definition for the tree node structure
*/

/* Begin inclusion-prevention mechanism */
#ifndef NODE_H
#define NODE_H

/* Tree node definition */
typedef struct node{
  struct node *l;
  struct node *r;
  char id[2];
  char string[255];
  int depth;
} node_t;

/* End inclusion-prevention mechanism */
#endif /* NODE_H */
