#include <stdio.h>
#include <string.h>
#include "types.h"

char* trim(char* buffer) {
  Int16 p;
  p = strlen(buffer) - 1;
  while (p >= 0 && buffer[p] > 0 && buffer[p] <= ' ') {
    buffer[p] = 0;
    p--;
    }
  while (buffer[0] > 0 && buffer[0] <= ' ') buffer++;
  return buffer;
  }

char* nextLine(FILE* file) {
  static char line[1024];
  if (fgets(line,1024,file) == NULL) return NULL;
  return trim(line);
  }

Int8 startsWith(char* buffer, const char* check) {
  if (strncasecmp(buffer,check,strlen(check)) == 0) return -1;
  return 0;
  }

char* nw(char* buffer) {
  while (buffer[0] > 0 && buffer[0] != ' ') buffer++;
  while (buffer[0] > 0 && buffer[0] == ' ') buffer++;
  return buffer;
  }

