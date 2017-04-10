/*
    Tim M. Lael
    CS4280
    p0
    13-FEB 2017
*/
/*
main.c
Source file containing main(). Program master.
*/

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "node.h"
#include "traversals.h"
#include "buildtree.h"
#include "utils.h"


int main(int argc, char* argv[]){
  /*************************************************************************************************/
  /*  Data Setup Area                                                                              */
  /*************************************************************************************************/

  /* input and temp file pointers */
  FILE *inputfp, *tempfp;
  /* Output base file name and implicit file extension */
  char *outputBase;
  static const char *EXTENSION = ".datE01";

  /* Character array to read lines into. Arbitrarily chosen max length of 255 */
  char line[255];
  /* temporary file for storing read strings */
  tempfp = fopen("tempSpace", "w");
  /* End data setup */

  /*************************************************************************************************/
  /*  Command Line Argument Parsing AND Input Keyboard/File Reading                                */
  /*************************************************************************************************/

  /* Error on improper usage */
  if (argc > 2){
    printf("\nInvalid number of arguments.\n\n");
    printf("Usage:\n");
    printf("./P0\t\t - Invokes program and user is prompted for input.\n");
    printf("\t\t Keyboard simulated EOF terminates input.\n");
    printf("./P0 < filename\t - Invokes program and input is read via stdin file redirection.\n");
    printf("\t\t filename must be precise including extension (if any).\n");
    printf("./P0 filename\t - Invokes program and input is read directly from file.\n");
    printf("\t\t filename should not include implicit extension (.datE01)\n\n");
    exit(EXIT_FAILURE);
}

  /* case argc == 1: default run with no input file provided or redirection */
  /* redirection requires explicit file naming or bash redirection will fail */
  else if(argc == 1){
    /* input file pointer points to stdin/redirect */
    inputfp = stdin;

    /* default output base file name (e.g. out.inorder) */
    outputBase = "out";

    /* unlikely, but covers stdin open failure */
    if (inputfp == NULL){
      fprintf(stderr, "Unable to open stdin: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }

    /* Ask user for input if not redirected */
    if (isatty(0)){
      printf("\nNo filename given or redirection detected. \nEnter strings or characters (must begin with lower alpha): ");
    }

    /*
    start reading token at something other than white-space,
    and stop reading a single token when you get to whitespace
    */
    while (scanf(" %s[^ \t\n]%*c", line) == 1 && argc == 1){
      /* Ask user for input if not redirected */
      if (isatty(0)){
	  	if(!islower(line[0])){
			printf("\n\nInvalid input - %s - detected.\n\n", line);
      		exit(EXIT_FAILURE);
		}
        printf("\nString read from stdin.\n Enter next value or EOF to quit: ");
      }
      fprintf(tempfp, "%s\n", line);
    }

    if (feof(inputfp)){
     printf("\nStdin read complete.\n\n");
     fclose(inputfp);
     fclose(tempfp);
    }
  }

  /* case else: file name (less extension) provided for input read */
  else{
    /* input file pointer points to file provided in argv[1] with implicit extension concated */
    char *fileName = malloc(sizeof(argv[1]) + sizeof(EXTENSION));
    strncat(fileName, argv[1], strlen(argv[1]));
    strncat(fileName, EXTENSION, strlen(EXTENSION));
    inputfp = fopen(fileName, "r");

    /* output base file name set to reflect input file (e.g. xxx.inorder) */
    outputBase = malloc(sizeof(argv[1]));
    outputBase = argv[1];

    /* covers input file open failure */
    if (inputfp == NULL){
      fprintf(stderr, "Unable to open '%s': %s\n", argv[1], strerror(errno));
      exit(EXIT_FAILURE);
    }

    /*
    start reading token at something other than white-space,
    and stop reading a single token when you get to whitespace
    */
    while(fscanf(inputfp, " %s[^ \t\n]%*c", line) == 1 && argc > 1){
      fprintf(tempfp, "%s\n", line);
    }

    if (feof(inputfp)){
      printf("\nFile read complete.\n\n");
      fclose(inputfp);
      fclose(tempfp);
    }
  }
  /* End Command Line Argument Parsing AND Input Keyboard/File Reading */

  /*************************************************************************************************/
  /*  Tree Building                                                                                */
  /*************************************************************************************************/

  /* Build the tree */
  tempfp = fopen("tempSpace", "r");
  if (tempfp == NULL){
    fprintf(stderr, "Unable to open tempSpace for reading into tree: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  buildTree(tempfp);

  fclose(tempfp);
  /* End Tree Building */

  /*************************************************************************************************/
  /*  Tree Traversal And Printing                                                                  */
  /*************************************************************************************************/
  /* Traverse and print the tree three different ways (functions defined in traversals.h and traversals.c)*/
  /* In Order Walk/Print */
  inorder(root, outputBase);
  /* Pre-Order Walk/Print */
  preorder(root, outputBase);
  /* Post-Order Walk/Print */
  postorder(root, outputBase);
  /* End Tree Traversal And Printing*/
  printf("\nOutput complete.\n\n");
  cleanup();
  return 0;
}
