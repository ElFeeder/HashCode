#include "Challenge.h"

int main(int argc, char** argv)  {
  FILE *input;
  int numberLibraries, i;
  unsigned long numberDiffBooks, days;
  int *bookScore;
  LIBRARY *libraryList;

  input = openFile(argv[1], "r");

  fscanf(input, "%lud %d %lud", &numberDiffBooks, &numberLibraries, &days);

  bookScore = (int *)malloc(numberDiffBooks * sizeof(int));

  for(i = 0; i < numberDiffBooks; i++)
    fscanf(input, "%d ", &bookScore[i]);

  libraryList = makeList(numberLibraries, input);

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
    fscanf(input, "%d", &libraryList[i].scanNumber);

    libraryList[i].ID = (int *)malloc(libraryList[i].numberBooks * sizeof(int));
    
    for(a = 0; a < libraryList[i].numberBooks; a++)
      fscanf(input, "%d ", &libraryList[i].ID[a]);
  }

  return libraryList;
}