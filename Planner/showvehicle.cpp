#include "header.h"

void ShowVehicle(Int8 vehicle) {
  char buffer[64];
  Lander* model;
  model = new Lander(vehicle);
  GotoXY(23, 3); WriteLn("Vehicle:    1. Apollo");
  GotoXY(23, 4); WriteLn("            2. Apollo J");
  GotoXY(23, 5); WriteLn("            3. Apollo Mk II");
  GotoXY(23, 6); WriteLn("            4. Apollo Mk III");
  GotoXY(32, 2+vehicle); Write("-->"); Flush();
  GotoXY(20, 8); Write("Ascent Stage");
  GotoXY(50, 8); Write("Descent Stage");
  GotoXY(5, 10); Write(" Dry Weight:");
  GotoXY(5, 11); Write("       Fuel:");
  GotoXY(5, 12); Write("     Oxygen:");
  GotoXY(5, 13); Write("    Battery:");
  GotoXY(5, 14); Write("     Thrust:");
  GotoXY(5, 15); Write("        Isp:");
  GotoXY(5, 16); Write("    Delta-V:");
  GotoXY(5, 17); Write("Full Weight:");
  GotoXY(5, 18); Write("   Rcs Fuel:");
  GotoXY(5, 19); Write(" Rcs Thrust:");
  GotoXY(5, 20); Write("    Rcs Isp:");
  sprintf(buffer,"%.0lf kg   ", model->AscentEmptyWeight());
  GotoXY(20,10); Write(buffer);
  sprintf(buffer,"%.0lf kg   ", model->AscentFuel());
  GotoXY(20,11); Write(buffer);
  GotoXY(20,12); Write("10 hrs  ");     /* Ascent Oxygen */
  GotoXY(20,13); Write("10 hrs  ");     /* Ascent Battery */
  sprintf(buffer,"%.0lf n   ", model->AscentThrust());
  GotoXY(20,14); Write(buffer);
  sprintf(buffer,"%.0lf s   ", model->AscentIsp());
  GotoXY(20,15); Write(buffer);
  sprintf(buffer,"%.0lf m/s   ", model->AscentDeltaV());
  GotoXY(20,16); Write(buffer);
  sprintf(buffer,"%.0lf kg   ", model->AscentFullWeight());
  GotoXY(20,17); Write(buffer);
  sprintf(buffer,"%.0lf kg   ", model->RcsFuel());
  GotoXY(20,18); Write(buffer);
  sprintf(buffer,"%.0lf n   ", model->RcsThrust());
  GotoXY(20,19); Write(buffer);
  sprintf(buffer,"%.0lf s   ", model->RcsIsp());
  GotoXY(20,20); Write(buffer);
  sprintf(buffer,"%.0lf kg   ", model->DescentEmptyWeight());
  GotoXY(50,10); Write(buffer);
  sprintf(buffer,"%.0lf kg   ", model->DescentFuel());
  GotoXY(50,11); Write(buffer);
  sprintf(buffer,"%d hrs   ", model->Consumables() / 3600);
  GotoXY(50,12); Write(buffer);
  sprintf(buffer,"%d hrs   ", model->Consumables() / 3600);
  GotoXY(50,13); Write(buffer);
  sprintf(buffer,"%.0lf n   ", model->DescentThrust());
  GotoXY(50,14); Write(buffer);
  sprintf(buffer,"%.0lf s   ", model->DescentIsp());
  GotoXY(50,15); Write(buffer);
  sprintf(buffer,"%.0lf m/s   ", model->DescentDeltaV());
  GotoXY(50,16); Write(buffer);
  sprintf(buffer,"%.0lf kg  ", model->DescentFullWeight());
  GotoXY(50,17); Write(buffer);
  Flush();
  delete(model);
  }

