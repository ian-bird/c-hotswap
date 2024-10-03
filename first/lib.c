#include <string.h>
#include <stdlib.h>

char *getOutputStrOwn()
{
  const char *str = "This is from the first shared object.";
  // need to malloc our string since it must persist after returning
  char *result = malloc(strlen(str) * sizeof(char));
  strcpy(result, str);

  return result;
}