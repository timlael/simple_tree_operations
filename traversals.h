/*
    Tim M. Lael
    CS4280
    p0
    13-FEB 2017
*/
/*
traversals.h
This is the header file which contains function prototypes for the tree
traversal and output printing/formatting functions.
*/

/* Begin inclusion-prevention mechanism */
#ifndef TRAVERSALS_H
#define TRAVERSALS_H

void preorder(node_t *root, char *outputBase);
void inorder(node_t *root, char *outputBase);
void postorder(node_t *root, char *outputBase);
void IOTW(node_t *n, FILE *outputFile);
void PRTW(node_t *n, FILE *outputFile);
void PSTW(node_t *n, FILE *outputFile);
/* End inclusion-prevention mechanism */
#endif /* TRAVERSALS_H */
