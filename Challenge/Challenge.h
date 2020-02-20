#ifndef CHALLENGE_H
#define CHALLENGE_H

#include <stdio.h>
#include <stdlib.h>


typedef struct book {
  unsigned int id;
  int *score;
}BOOK;
  
  
typedef struct library  {
  int numberBooks;
  int signup;
  unsigned int scanNumber;
  BOOK *id;
  int effectiveTime;
  int maxOutput;
  int libraryScore;
}LIBRARY;


/* Main.c */
FILE* openFile(char *name, char *mode);

LIBRARY* makeList(int numberLibraries, FILE *input);

void quicksort(int *bookScore, int first, int last);

#endif