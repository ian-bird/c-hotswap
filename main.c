#include <stdio.h>
#include <dlfcn.h>

#ifndef LIB_H
#define LIB_H
#include "lib.h"
#endif

int main(int argc, char *argv[])
{
  FILE *soFile;
  void *handle; 
  char *toPrint;

  soFile = fopen("first.so", "r");
  if(soFile == NULL)
  {
    fprintf(stderr, "could not open first.so");
    return 1;
  }

  handle = dlopen(soFile, RTLD_NOW | RTLD_GLOBAL); 
  if(handle == NULL)
  {
    fprintf(stderr, "could not load first.so");
    return 1;
  }

  toPrint = getOutputStrOwn();
  if(toPrint == NULL)
  {
    fprintf(stderr, "invalid response from getOutputStrOwn");
    return 1;
  }

  printf("%s\n", toPrint);

  free(toPrint);
  dlclose(handle);
  fclose(soFile);

  soFile = fopen("second.so", "r");
  if(soFile == NULL)
  {
    fprintf(stderr, "could not open second.so");
    return 1;
  }

  handle = dlopen(soFile, RTLD_NOW | RTLD_GLOBAL);
  if(handle == NULL)
  {
    fprintf(stderr, "could not load second.so");
    return 1;
  }

  toPrint = getOutputStrOwn();
  if(toPrint == NULL)
  {
    fprintf(stderr, "invalid response from getOutputStrOwn");
    return 1;
  }
  
  printf("%s\n", toPrint);

  free(toPrint);
  dlclose(handle);
  fclose(soFile);

  return 0;
}