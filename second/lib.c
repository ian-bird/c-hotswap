#include <string.h>
#include <stdlib.h>

extern char *getOutputStrOwn()
{
  const char *str = "This is from the second library.";
  // need to malloc our string since it must persist after returning
  char *result = malloc(strlen(str) * sizeof(char));
  strcpy(result, str);

  return result;
}