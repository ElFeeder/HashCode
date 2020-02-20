#ifndef CHALLENGE_H
#define CHALLENGE_H

#include <stdio.h>
#include <stdlib.h>
  
  
typedef struct library  {
  int numberBooks;
  int signup;
  unsigned int scanNumber;
  unsigned int *id;
  int effectiveTime;
  int maxOutput;
  int libraryScore;
  int availability;
}LIBRARY;


/* Main.c */
FILE* openFile(char *name, char *mode);

LIBRARY* makeList(int numberLibraries, FILE *input);

void quicksort(int *bookScore, int first, int last);

#endif