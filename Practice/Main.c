#include "Practice.h"


int main(int argc, char **argv)  {
  FILE *input = NULL, *output = NULL;
  int people, differentPizza, new;
  int i = 0, max = 0, next = 2;
  int *slices, *coef, *final;


  input = openFile(input, argv[1]);
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

  /*for(i = 0; i < differentPizza; i++) {
    printf("%d ", coef[i]);
  }
  printf("\n");*/
  /*for(i = 0; i < differentPizza; i++) {
    printf("%d ", slices[i]);
  }
  printf("\n");*/
  while(next < pow(2, differentPizza))  {
    new = count(coef, slices, differentPizza);

    printf("%d\n", new);
    if(new == people) {
      final = coef;
      break;
    }
    
    if(new > max && new < people)  {
      printf("entered 2\n");
      final = coef;
      for(i = 0; i < differentPizza; i++)
        printf("%d ", final[i]);
      printf("\n");
      max = new;
    }
    
    changeCoef(coef, differentPizza, next);
    /*for(i = 0; i < differentPizza; i++)
      printf("%d ", coef[i]);
    printf("\n");*/
    next++;
  }

  writeOnFile(final, differentPizza, coef, slices);

  return 0;
}


void writeOnFile(int *final, int differentPizza, int *coef, int *slices)  {
  int i, cont = 0;
  
  for(i = 0; i < differentPizza; i++) {
    if(final[i] == 1)
      cont++;
  }
  printf("%d\n", cont); /* How many different pizzas to order */

  for(i = 0; i < differentPizza; i++) {
    if(coef[i] == 1)
      printf("%d ", slices[i]); /* What pizzas to order */
  }
  printf("\n");
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


FILE* openFile(FILE *fp, char* name)  {
  fp = fopen(name, "r");
  if(fp == NULL) {
    printf("ERROR. Can't open file %s.\n", name);
    exit(1);
  }

  return fp;
}