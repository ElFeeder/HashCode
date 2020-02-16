#include "Practice.h"

FILE* openFile(FILE *fp, char* name)  {
  fp = fopen(name, "r");
  if(fp == NULL) {
    printf("ERROR. Can't open file %s.\n", name);
    exit(1);
  }

  return fp;
}