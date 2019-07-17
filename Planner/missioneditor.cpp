#include "header.h"

void MissionEditor() {
  Double longitude;
  Double latitude;
  FILE* file;
  char buffer[256];
  int key;
  key = 0;
  Menu();
  while (key != 'q') {
    key = Inkey();
GotoXY(2,2);
    if (key == 27) key ='q';
    if (key =='Q') key = 'q';
    if (key =='S') key = 's';
    if (key =='a') key = 'A';
    if (key =='b') key = 'B';
    if (key =='c') key = 'C';
    if (key =='d') key = 'D';
    if (key =='e') key = 'E';
    if (key =='f') key = 'F';
    if (key =='g') key = 'G';
    if (key =='h') key = 'H';
    if (key =='i') key = 'I';
    if (key =='j') key = 'J';
    if (key == 'A') {
      GotoXY(24,3); Write("                                                ");
      if (Input(24,3,buffer,false)) {
        if (strlen(buffer) > 0) mission->Name(buffer);
        }
      Menu();
      }
    if (key == 'B') {
      GotoXY(24,4); Write("                                                ");
      if (Input(24,4,buffer,false)) {
        if (strlen(buffer) > 0) mission->Description(buffer);
        }
      Menu();
      }
    if (key == 'C') {
      GetRegion();
      Menu();
      }
    if (key == 'D' && mission->TargetLongitude() >=-180) {
      longitude = mission->TargetLongitude();
      latitude = mission->TargetLatitude();
      if (SelectFromMap(&latitude, &longitude)) {
        mission->TargetLongitude(longitude);
        mission->TargetLatitude(latitude);
        }
      Menu();
      }
    if (key == 'E' && mission->TargetLongitude() >=-180) {
      longitude = (mission->PrimaryLongitude() >= -180) ?
         mission->PrimaryLongitude() : mission->TargetLongitude();
      latitude = (mission->PrimaryLatitude() >= -180) ?
         mission->PrimaryLatitude() : mission->TargetLatitude();
      if (SelectFromMap(&latitude, &longitude)) {
        mission->PrimaryLongitude(longitude);
        mission->PrimaryLatitude(latitude);
        }
      Menu();
      }
    if (key == 'F' && mission->TargetLongitude() >=-180) {
      longitude = (mission->Secondary1Longitude() >= -180) ?
         mission->Secondary1Longitude() : mission->TargetLongitude();
      latitude = (mission->Secondary1Latitude() >= -180) ?
         mission->Secondary1Latitude() : mission->TargetLatitude();
      if (SelectFromMap(&latitude, &longitude)) {
        mission->Secondary1Longitude(longitude);
        mission->Secondary1Latitude(latitude);
        }
      Menu();
      }
    if (key == 'G' && mission->TargetLongitude() >=-180) {
      longitude = (mission->Secondary2Longitude() >= -180) ?
         mission->Secondary2Longitude() : mission->TargetLongitude();
      latitude = (mission->Secondary2Latitude() >= -180) ?
         mission->Secondary2Latitude() : mission->TargetLatitude();
      if (SelectFromMap(&latitude, &longitude)) {
        mission->Secondary2Longitude(longitude);
        mission->Secondary2Latitude(latitude);
        }
      Menu();
      }
    if (key == 'H' && mission->TargetLongitude() >=-180) {
      longitude = (mission->Secondary3Longitude() >= -180) ?
         mission->Secondary3Longitude() : mission->TargetLongitude();
      latitude = (mission->Secondary3Latitude() >= -180) ?
         mission->Secondary3Latitude() : mission->TargetLatitude();
      if (SelectFromMap(&latitude, &longitude)) {
        mission->Secondary3Longitude(longitude);
        mission->Secondary3Latitude(latitude);
        }
      Menu();
      }
    if (key == 'I') {
      SelectVehicle();
      Menu();
      }
    if (key == 'J') {
      DoLoadout();
      Menu();
      }
    if (key == 's') {
      Box(20,10,40,7);
      GotoXY(32,12); Write("Save Mission As:");
      if (Input(30,14,buffer,false)) {
        strcat(buffer,".msn");
        file = fopen(buffer,"w");
        mission->Save(file);
        fclose(file);
        key = 'q';
        }
      }
    }
  }

