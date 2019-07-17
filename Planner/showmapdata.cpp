#include "header.h"

void ShowMapData(Double latitude, Double longitude) {
  char buffer[128];
  sprintf(buffer,"%9.4f",latitude);
  GotoXY(66,4); Write(buffer);
  sprintf(buffer,"%9.4f",longitude);
  GotoXY(66,7); Write(buffer);
  sprintf(buffer,"%9.2fm",(latitude - mission->TargetLatitude())*METERS);
  GotoXY(66,10); Write(buffer);
  sprintf(buffer,"%9.2fm",(longitude - mission->TargetLongitude())*METERS);
  GotoXY(66,13); Write(buffer);
  }

