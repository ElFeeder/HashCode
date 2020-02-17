#include "Practice.h"


int main(void)  {
  FILE *input = NULL, *output = NULL;
  int people, differentPizza, i = 0;
  int *slices, *coef;


  input = openFile(input, (char *)"a_example.in");
  fscanf(input, "%d %d", &people, &differentPizza);
  slices = (int *)calloc(differentPizza, sizeof(int));
  coef = (int *)calloc(differentPizza, sizeof(int));

  initCoef(coef, differentPizza);
  while(i < differentPizza) {
    fscanf(input, "%d ", &(slices[i]));
    i++;
  }

  fclose(input);


  for(i = 0; i < differentPizza * 2; i++) {
    
  }
  return 0;
}

void initCoef(int *coef, int differentPizza)  {
  int i = 0;

  while(i < differentPizza) {
    if(i != (differentPizza - 1))
      coef[i] = 0;
    else
      coef[i] = 1;

    i++;
  }
}

FILE* openFile(FILE *fp, char* name)  {
  fp = fopen(name, "r");
  if(fp == NULL) {
    printf("ERROR. Can't open file %s.\n", name);
    exit(1);
  }

  return fp;
}