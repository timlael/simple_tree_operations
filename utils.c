/*
    Tim M. Lael
    CS4280
    p0
    13-FEB 2017
*/
/*
utils.c
This is the source file containing function the definition for the concat
utility used throughout the program.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

/*
function to concatenate strings with like starting characters
newest strings appear to the left with spaces separating each.
*/
char *concat(const char *s1, const char *s2){
  char *ns = malloc(snprintf(NULL, 0, "%s %s", s2, s1) + 1);
  sprintf(ns, "%s %s", s2, s1);
  return ns;
}

/* System call to remove temporary file */
void cleanup(){
  system("rm tempSpace");
}
