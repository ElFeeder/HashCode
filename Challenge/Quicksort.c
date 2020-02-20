#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct library  {
  int numberBooks;
  int signup;
  unsigned long scanNumber;
  unsigned long *id;
  int effectiveTime;
  int maxOutput;
  int libraryScore;
  int availability;
}LIBRARY;


void quicksort(unsigned long *bookScore, int first, int last) {
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
    quicksort(bookScore, j + 1, last);
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
  int *original;

  libraryList = (LIBRARY *)malloc(numberLibraries * sizeof(LIBRARY));
  
  for(i = 0; i < numberLibraries; i++)  {
    libraryList[i].availability = 1;

    fscanf(input, "%d ", &libraryList[i].numberBooks);
    fscanf(input, "%d ", &libraryList[i].signup);
    fscanf(input, "%lu", &libraryList[i].scanNumber);

    libraryList[i].id = (unsigned long *)malloc(libraryList[i].numberBooks * sizeof(unsigned long));
    
    original = (int *)malloc(libraryList[i].numberBooks * 2 * sizeof(int));
    
    for(a = 0; a < libraryList[i].numberBooks; a++) {
      fscanf(input, "%lu ", &libraryList[i].id[a]);
      original[a] = libraryList[i].id[a];
      original[a + libraryList[i].numberBooks] = libraryList[i].id[a];
      /*printf("here - %lu\n", libraryList[i].id[a]);*/
      libraryList[i].id[a] = bookScore[libraryList[i].id[a]];
      /*printf("here - %lu\n", libraryList[i].id[a]);*/
    }

    quicksort(libraryList[i].id, 0, libraryList[i].numberBooks);

    /*for(a = 0; a < libraryList[i].numberBooks; a++)
      printf("bla - %lu\n", libraryList[i].id[a]);*/

    libraryList[i].id[a] = 
  }

  return libraryList;
}


void writeOnFile(char *originalName, unsigned long numberDiffBooks, int numberLibraries, unsigned long days, LIBRARY *libraryList, int *bookScore)  {
  int i, a;
  FILE *output = NULL;

  output = openFile(strcat(strtok(originalName, "."), ".qsort"), "w");

  fprintf(output, "%lu %d %lu\n", numberDiffBooks, numberLibraries, days);

  for(i = 0; i < numberDiffBooks; i++)
    fprintf(output, "%d ", bookScore[i]);
  
  fprintf(output, "\n");

  for(i = 0; i < numberLibraries; i++)  {
    fprintf(output, "%d %d %lu\n", libraryList[i].numberBooks, libraryList[i].signup, libraryList[i].scanNumber);
    for(a = 0; a < libraryList[i].numberBooks; a++)
      fprintf(output, "%lu ", libraryList[i].id[a]);
    fprintf(output, "\n");
  }
  fprintf(output, "\n");


  fclose(output);
}


int main(int argc, char** argv) {
  FILE *input;
  int numberLibraries, i;
  unsigned long numberDiffBooks, days;
  int *bookScore;
  LIBRARY *libraryList;


  input = openFile(argv[1], "r");

  fscanf(input, "%lu ", &numberDiffBooks);
  fscanf(input, "%d ", &numberLibraries);
  fscanf(input, "%lu", &days);

  /*printf("we good");*/
  
  bookScore = (int *)malloc(numberDiffBooks * sizeof(int));

  for(i = 0; i < numberDiffBooks; i++)
    fscanf(input, "%d ", &bookScore[i]);

  libraryList = makeList(numberLibraries, input, bookScore);

  /*for(i = 0; i < numberDiffBooks; i++)  {
    printf("%d ", bookScore[i]);
  }
  printf("\n");*/

  writeOnFile(argv[1], numberDiffBooks, numberLibraries, days, libraryList, bookScore);
  
  return 0;
}