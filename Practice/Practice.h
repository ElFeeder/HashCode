#ifndef PRACTICE_H
#define PRACTICE_H


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TOLE 0.82
#define MULTI 0.0135


/*  Main.c  */
void writeOnFile(int *final, int differentPizza, int *slices, char *originalName);

unsigned long RecursiveSearch (int *final, int *slices,float tolerance,unsigned long people,int startPoint, unsigned long lastResult);

FILE* openFile(FILE *fp, char* name, char *mode);


#endif
