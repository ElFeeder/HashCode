#include "Practice.h"


int main(int argc, char **argv)  {
  FILE *input = NULL;
  int differentPizza, i = 0;
  int *slices, *final;
  unsigned long people;

  input = openFile(input, argv[1], "r");
  fscanf(input, "%lu %d", &people, &differentPizza);

  slices = (int *)calloc(differentPizza, sizeof(int));
  final = (int *)calloc(differentPizza, sizeof(int));

  while(i < differentPizza) {
    fscanf(input, "%d ", &(slices[i]));
    i++;
  }

  fclose(input);

  RecursiveSearch (final, slices, 0.999, people, differentPizza - 1,0);
  writeOnFile(final, differentPizza, argv[1]);

  return 0;
}


void writeOnFile(int *final, int differentPizza, char *originalName)  {
  int i, cont = 0;
  FILE *output = NULL;

  output = openFile(output, strcat(strtok(originalName, "."), ".out"), "w");

  for(i = 0; i < differentPizza; i++) {
    if(final[i] == 1)
      cont++;
  }
  fprintf(output, "%d\n", cont); /* How many different pizzas to order */

  cont = 0;
  for(i = 0; i < differentPizza; i++) {
    if(final[i] == 1)
      fprintf(output, "%d ", i); /* What pizzas to order */
  }

  fclose(output);
}

FILE* openFile(FILE *fp, char* name, char *mode)  {
  fp = fopen(name, mode);
  if(fp == NULL) {
    printf("ERROR. Can't open file %s.\n", name);
    exit(1);
  }

  return fp;
}

unsigned long RecursiveSearch (int *final, int *slices, float tolerance, unsigned long people, int startPoint, unsigned long lastResult) {
  for (;startPoint >= 0 && lastResult <= people*tolerance ;startPoint--)  {
    lastResult = lastResult + slices[startPoint];
    if (lastResult > people)  {
      lastResult = lastResult - slices [startPoint];
      RecursiveSearch (final,slices,tolerance,people,startPoint-1,lastResult);
      continue;
    }
    final[startPoint] = 1;
  }
  return lastResult;
}
