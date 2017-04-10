/*
    Tim M. Lael
    CS4280
    p0
    13-FEB 2017
*/
/*
buildtree.h
This is the header file which contains function prototypes for the tree
building and node placement functions.
The root node is also declared here for global use by inclusion of this
header file.
*/

/* Begin inclusion-prevention mechanism */
#ifndef BUILDTREE_H
#define BUILDTREE_H

/* Global root node declaration */
extern node_t *root;

void buildTree(FILE *tempFile);
void findPlace(node_t *searchNode);

/* End inclusion-prevention mechanism */
#endif /* BUILDTREE_H */
