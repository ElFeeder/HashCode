#include "Challenge.h"

int main(int argc, char** argv)  {
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

  quicksort(bookScore, 0, numberDiffBooks);

  libraryList = makeList(numberLibraries, input);

  for(i = 0; i < numberDiffBooks; i++)  {
    printf("%d ", bookScore[i]);
  }
  printf("\n");
  
  
  return 0;
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


LIBRARY* makeList(int numberLibraries, FILE *input) {
  LIBRARY *libraryList;
  int i, a;

  libraryList = (LIBRARY *)malloc(numberLibraries * sizeof(LIBRARY));

  for(i = 0; i < numberLibraries; i++)  {
    fscanf(input, "%d ", &libraryList[i].numberBooks);
    fscanf(input, "%d ", &libraryList[i].signup);
    fscanf(input, "%u", &libraryList[i].scanNumber);

    libraryList[i].id = (BOOK *)malloc(libraryList[i].numberBooks * sizeof(BOOK));
    
    for(a = 0; a < libraryList[i].numberBooks; a++)
      fscanf(input, "%u ", &libraryList[i].id[a].id);
  }

  return libraryList;
}

void quicksort(int *bookScore, int first, int last) {
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