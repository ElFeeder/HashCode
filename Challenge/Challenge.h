#include <stdio.h>
#include <stdlib.h>


typedef struct id {
  unsigned int *id;
  int *score;
}ID;
  
  
typedef struct library  {
  int numberBooks;
  int signup;
  unsigned int scanNumber;
  ID id;
  int effectiveTime;
  int maxOutput;
  int libraryScore;
}LIBRARY;


/* Main.c */
FILE* openFile(char *name, char *mode);

LIBRARY* makeList(int numberLibraries, FILE *input);