#include <stdio.h>
#include <stdlib.h>


unsigned int *bookScore;

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


void quicksort(unsigned int *bookScore, int first, int last) {
  int i, j, pivot, temp;

   if(first < last) {
    pivot = first;
    i = first;
    j = last;

    while(i < j)  {
      while(bookScore[i] <= bookScore[pivot] && i < last)
        i++;
      while(bookScore[j] > bookScore[pivot])
        j--;
      if(i < j) {
        temp = bookScore[i];
        bookScore[i] = bookScore[j];
        bookScore[j] = temp;
      }
    }

    temp = bookScore[pivot];
    bookScore[pivot] = bookScore[j];
    bookScore[j] = temp;

    quicksort(bookScore, first, j - 1);
    quicksort(bookScore, j+1, last);
   }
}


FILE* openFile(char *name, char *mode)  {
  FILE *input;

  input = fopen(name, mode);
  if(input == NULL) {
    printf("ERROR. Can't open file %s.\n", name);
    exit(1);
  }

  return input;
}


LIBRARY* makeList(int numberLibraries, FILE *input, int *bookScore) {
  LIBRARY *libraryList;
  int i, a;

  libraryList = (LIBRARY *)malloc(numberLibraries * sizeof(LIBRARY));
  
  for(i = 0; i < numberLibraries; i++)  {
    libraryList[i].availability = 1;

    fscanf(input, "%d ", &libraryList[i].numberBooks);
    fscanf(input, "%d ", &libraryList[i].signup);
    fscanf(input, "%u", &libraryList[i].scanNumber);

    libraryList[i].id = (unsigned int *)malloc(libraryList[i].numberBooks * sizeof(unsigned int));
    
    for(a = 0; a < libraryList[i].numberBooks; a++) {
      fscanf(input, "%u ", &libraryList[i].id[a]);
      libraryList[i].id[a] = bookScore[libraryList[i].id[a]];
    }

    quicksort(libraryList[i].id, 0, libraryList[i].numberBooks);
  }

  return libraryList;
}


void writeOnFile(char *originalName)  {
  int i, cont = 0;
  FILE *output = NULL;

  output = openFile(output, strcat(strtok(originalName, "."), ".qsort"), "w");

  fprintf(output, "%d %d %d\n ")


  
  cont = 0;
  for(i = 0; i < differentPizza; i++) {
    if(final[i] == 1) {
      fprintf(output, "%d ", slices[i]); /* What pizzas to order */
      cont += slices[i];
    }
  }
  fprintf(output, "\n%d\n", cont);

  fclose(output);
}


int main(int argc, char** argv) {
  FILE *input;
  int numberLibraries, i;
  unsigned long numberDiffBooks, days;
  int *bookScore;
  LIBRARY *libraryList;


  input = openFile(argv[1], "r");

  fscanf(input, "%lud ", &numberDiffBooks);
  fscanf(input, "%d ", &numberLibraries);
  fscanf(input, "%lud", &days);

  bookScore = (int *)malloc(numberDiffBooks * sizeof(int));

  for(i = 0; i < numberDiffBooks; i++)
    fscanf(input, "%d ", &bookScore[i]);

  libraryList = makeList(numberLibraries, input, bookScore);

  for(i = 0; i < numberDiffBooks; i++)  {
    printf("%d ", bookScore[i]);
  }
  printf("\n");

  writeOnFile(argv[1]);
  
  return 0;
}