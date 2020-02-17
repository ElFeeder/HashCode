#ifndef PRACTICE_H
#define PRACTICE_H


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*  Main.c  */
void initCoef(int *coef, int differentPizza);
void changeCoef(int *coef, int differentPizza, int number);
void writeOnFile(int *final, int differentPizza, int *coef, int *slices);

int count(int *coef, int *slices, int differentPizza);

FILE* openFile(FILE *fp, char* name);
#endif