#include <stdlib.h>
#include <string.h>

//returned buffer should be dynamically allocated and will be freed by a caller

char *solution(const char *camelCase)
{
  char *sol_buffer = calloc(512, sizeof(char));
  if (sol_buffer == NULL) return NULL;
  
  char *temp = sol_buffer;

  for (const char *c = camelCase; *c; c++)
  {
    if (65 <= *c && 90 >= *c)
    {
      *temp++ = ' ';
      *temp++ = *c;
    }
    else 
    {
      *temp++ = *c;
    }
  }
  
  return sol_buffer;
}
