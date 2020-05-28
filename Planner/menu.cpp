#include "header.h"

void Menu() {
  char buffer[256];
  ClearScreen();
  GotoXY(5,3); Write("A. Mission Name   :");
  if (mission->Name() == NULL) WriteLn("Not Defined");
    else {
      sprintf(buffer,"%s",mission->Name());
      WriteLn(buffer);
      }
  GotoXY(5,4); Write("B. Description    :");
  if (mission->Description() == NULL) WriteLn("Not Defined");
    else {
      sprintf(buffer,"%s",mission->Description());
      WriteLn(buffer);
      }
  GotoXY(5,5); Write("C. Landing Region :");
  if (mission->Region() == NULL) WriteLn("Not Defined");
    else {
      sprintf(buffer,"%s",mission->Region());
      WriteLn(buffer);
      }
  GotoXY(5,6); Write("D. Landing Site   :");
  if (mission->TargetLatitude() < -180) WriteLn("Not Defined");
    else {
      sprintf(buffer,"Latitude: %9.4f, Longitude: %9.4f",
         mission->TargetLatitude(), mission->TargetLongitude());
      WriteLn(buffer);
      }
  GotoXY(5,7); Write("E. Primary Site   :");
  if (mission->PrimaryLatitude() < -180) WriteLn("Not Defined");
    else {
      sprintf(buffer,"Latitude: %9.4f, Longitude: %9.4f",
         mission->PrimaryLatitude(), mission->PrimaryLongitude());
      WriteLn(buffer);
      }
  GotoXY(5,8); Write("F. Secondary Site :");
  if (mission->Secondary1Latitude() < -180) WriteLn("Not Defined");
    else {
      sprintf(buffer,"Latitude: %9.4f, Longitude: %9.4f",
         mission->Secondary1Latitude(), mission->Secondary1Longitude());
      WriteLn(buffer);
      }
  GotoXY(5,9); Write("G. Secondary Site :");
  if (mission->Secondary2Latitude() < -180) WriteLn("Not Defined");
    else {
      sprintf(buffer,"Latitude: %9.4f, Longitude: %9.4f",
         mission->Secondary2Latitude(), mission->Secondary2Longitude());
      WriteLn(buffer);
      }
  GotoXY(5,10); Write("H. Secondary Site :");
  if (mission->Secondary3Latitude() < -180) WriteLn("Not Defined");
    else {
      sprintf(buffer,"Latitude: %9.4f, Longitude: %9.4f",
         mission->Secondary3Latitude(), mission->Secondary3Longitude());
      WriteLn(buffer);
      }
  GotoXY(5,11); Write("I. Vehicle        :");
  if (mission->Vehicle() == 1) WriteLn("Apollo      ");
  if (mission->Vehicle() == 2) WriteLn("Apollo J    ");
  if (mission->Vehicle() == 3) WriteLn("Apollo Mk II");
  if (mission->Vehicle() == 4) WriteLn("Apollo Mk III");
  GotoXY(5,12); Write("J. Loadout");
  GotoXY(5,13); Write("K. CSM Orbit      : ");
  sprintf(buffer,"LAN: %6.2f  INC: %6.2f",mission->StartLAN(), mission->StartInc());
  WriteLn(buffer);
  GotoXY(5,18); WriteLn("S. Save and exit");
  GotoXY(5,19); WriteLn("Q. Quit without saving");
  GotoXY(8,21); Write("Option ? ");
  Flush();
  }

