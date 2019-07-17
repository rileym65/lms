#include "header.h"

void ShowSelections(UInt32 top, UInt32 count) {
  UInt32 i;
  UInt32 f;
  char lat[20];
  char lng[20];
  char buffer[80];
  Box(3,2,76,20);
  for (i=0; i<count; i++) {
    f = selections[top+i];
    if (features[f].latitude < 0)
      sprintf(lat,"%6.2fS",-features[f].latitude);
    else
      sprintf(lat,"%6.2fN",features[f].latitude);
    if (features[f].longitude < 0)
      sprintf(lng,"%7.2fW",-features[f].longitude);
    else
      sprintf(lng,"%7.2fE",features[f].longitude);
    sprintf(buffer,"%-50s %-8s %-8s",features[f].name,lat,lng);
    GotoXY(9,3+i); Write(buffer);
    }
  Flush();
  }

