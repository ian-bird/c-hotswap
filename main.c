#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
  void *handle; 
  char *toPrint;
  char *(*getOutputStrOwn)();

  handle = dlopen("first.dylib", RTLD_NOW | RTLD_GLOBAL); 
  if(handle == NULL)
  {
    fprintf(stderr, "could not load first.so");
    return 1;
  }

  getOutputStrOwn = dlsym(handle, "getOutputStrOwn");
  if(getOutputStrOwn == NULL)
  {
    fprintf(stderr, "could not find getOutputStrOwn");
    return 1;
  }

  toPrint = (*getOutputStrOwn)();
  if(toPrint == NULL)
  {
    fprintf(stderr, "invalid response from getOutputStrOwn");
    return 1;
  }

  printf("%s\n", toPrint);

  free(toPrint);
  dlclose(handle);

  handle = dlopen("second.dylib", RTLD_NOW | RTLD_GLOBAL);
  if(handle == NULL)
  {
    fprintf(stderr, "could not load second.so");
    return 1;
  }

  getOutputStrOwn = dlsym(handle, "getOutputStrOwn");
  if(getOutputStrOwn == NULL)
  {
    fprintf(stderr, "could not find getOutputStrOwn");
    return 1;
  }

  toPrint = (*getOutputStrOwn)();
  if(toPrint == NULL)
  {
    fprintf(stderr, "invalid response from getOutputStrOwn");
    return 1;
  }
  
  printf("%s\n", toPrint);

  free(toPrint);
  dlclose(handle);

  return 0;
}