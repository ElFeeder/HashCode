#ifndef PRACTICE_H
#define PRACTICE_H


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


/*  Main.c  */
void writeOnFile(int *final, int differentPizza, char *originalName);

unsigned long RecursiveSearch (int *final, int *slices,float tolerance,unsigned long people,int startPoint, unsigned long lastResult);

FILE* openFile(FILE *fp, char* name, char *mode);


#endif
