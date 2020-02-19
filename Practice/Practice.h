#ifndef PRACTICE_H
#define PRACTICE_H


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TOLE 0.80
#define MULTI 0.0027


/*  Main.c  */
void initCoef(int *coef, int differentPizza);
void changeCoef(int *coef, int differentPizza, int number);
void writeOnFile(int *final, int differentPizza, int *slices, char *originalName);

int count(int *coef, int *slices, int differentPizza);

FILE* openFile(FILE *fp, char* name, char *mode);
#endif