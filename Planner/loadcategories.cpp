#include "header.h"

void LoadCategories() {
  UInt32 i;
  UInt32 len;
  Boolean flag;
  char   cat[128];
  char*  pos;
  for (i=0; i<numFeatures; i++) {
    pos = strchr(features[i].name,' ');
    if (pos != NULL) {
      len = pos - features[i].name;
      strncpy(cat,features[i].name,len);
      cat[len] = 0;
      if (!CategoryExists(cat)) {
        if (++numCategories == 1)
          categories = (char**)malloc(sizeof(char*));
        else
          categories = (char**)realloc(categories, sizeof(char*) * numCategories);
        categories[numCategories-1] = (char*)malloc(strlen(cat) + 1);
        strcpy(categories[numCategories-1], cat);
        }
      }
    }
  flag = true;
  while (flag) {
    flag = false;
    for (i=0; i<numCategories-1; i++)
      if (strcmp(categories[i],categories[i+1]) > 0) {
        pos = categories[i];
        categories[i] = categories[i+1];
        categories[i+1] = pos;
        flag = true;
        }
    }
  }

