#include "Practice.h"


int main(int argc, char **argv)  {
  FILE *input = NULL;
  int people, differentPizza, new;
  int i = 0, max = 0, next = 2;
  int *slices, *coef, *final;


  input = openFile(input, argv[1], "r");
  fscanf(input, "%d %d", &people, &differentPizza);
  slices = (int *)calloc(differentPizza, sizeof(int));

  while(i < differentPizza) {
    fscanf(input, "%d ", &(slices[i]));
    i++;
  }

  fclose(input);

  final = (int *)calloc(differentPizza, sizeof(int));

  coef = (int *)calloc(differentPizza, sizeof(int));
  initCoef(coef, differentPizza);

  while(next < pow(2, differentPizza))  {
    new = count(coef, slices, differentPizza);

    if(new == people) {
      for(i = 0; i < differentPizza; i++)
        final[i] = coef[i];
      break;
    }
    
    if(new > max && new < people)  {
      for(i = 0; i < differentPizza; i++)
        final[i] = coef[i];
      max = new;
    }
    
    changeCoef(coef, differentPizza, next);
    next++;
  }

  writeOnFile(final, differentPizza, slices, argv[1]);

  return 0;
}


void writeOnFile(int *final, int differentPizza, int *slices, char *originalName)  {
  int i, cont = 0;
  FILE *output = NULL;

  output = openFile(output, strcat(strtok(originalName, ".in"), ".out"), "w");

  for(i = 0; i < differentPizza; i++) {
    if(final[i] == 1)
      cont++;
  }
  fprintf(output, "%d\n", cont); /* How many different pizzas to order */

  for(i = 0; i < differentPizza; i++) {
    if(final[i] == 1)
      fprintf(output, "%d ", slices[i]); /* What pizzas to order */
  }
  fprintf(output, "\n");

  fclose(output);
}


void changeCoef(int *coef, int differentPizza, int number)  {
  int cont, binary, i;

  for(cont = differentPizza - 1, i = 0; cont >= 0; cont--, i++) {
    binary = number >> cont;

    if(binary & 1)
      coef[i] = 1;
    else
      coef[i] = 0;
  }
}


int count(int *coef, int *slices, int differentPizza) {
  int i, new = 0;
  
  for(i = 0; i < differentPizza; i++) {
    if(coef[i] == 1)
      new += slices[i];
  }

  return new;
}


void initCoef(int *coef, int differentPizza)  {
  int i = 0;

  while(i < differentPizza - 1) {
    coef[i] = 0;
    i++;
  }
  coef[i] = 1;
}


FILE* openFile(FILE *fp, char* name, char *mode)  {
  fp = fopen(name, mode);
  if(fp == NULL) {
    printf("ERROR. Can't open file %s.\n", name);
    exit(1);
  }

  return fp;
}