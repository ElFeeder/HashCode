#include <stdio.h>
#include <stdlib.h>


typedef struct library  {
  int numberBooks;
  int signup;
  int scanNumber;
  int *ID;
  struct library *next;
}LIBRARY;


/* Main.c */
FILE* openFile(char *name, char *mode);

LIBRARY* makeList(int numberLibraries, FILE *input);