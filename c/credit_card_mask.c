#include <string.h>

char *maskify(char *masked, const char *string)
{
  int len = strlen(string);
  if (len < 4)
  {
    strcpy(masked, string);
    return masked;
  }
  
  int mask_len = len - 4;
  const char *p = string + mask_len;
  char *mp = masked;
  
  for (int i = 0; i < len; i++)
    *mp++ = (i < mask_len) ? '#' : *p++;

	*mp = '\0'; // write to masked
	return masked; // return it
}
