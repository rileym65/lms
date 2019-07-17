#include "header.h"

void ShowLoadout() {
  char buffer[64];
  Double pay;
  Double dry;
  Double full;
  Double deltaV;
  Double cons;
  sprintf(buffer,"%6.0f kg",mission->Model()->AscentEmptyWeight());
  GotoXY(C2,5); Write(buffer);
  sprintf(buffer,"%6.0f kg",mission->AscentFuel());
  GotoXY(C1,6); Write(buffer);
  GotoXY(C2,6); Write(buffer);
  sprintf(buffer,"%6.0f kg",mission->RcsFuel());
  GotoXY(C1,7); Write(buffer);
  GotoXY(C2,7); Write(buffer);
  dry = mission->Model()->AscentEmptyWeight() + mission->RcsFuel();
  full = dry + mission->AscentFuel();
  pay = full;
  sprintf(buffer,"%6.0f kg",full);
  GotoXY(C2,8); Write(buffer);
  deltaV = (mission->Model()->AscentIsp() * 9.80655) * log(full/dry);
  sprintf(buffer,"%6.0f m/s",deltaV);
  GotoXY(C2,9); Write(buffer);

  dry = mission->Model()->DescentEmptyWeight();
  sprintf(buffer,"%6.0f kg",dry);
  GotoXY(C2,12); Write(buffer);
  sprintf(buffer,"%6.0f kg",mission->DescentFuel());
  GotoXY(C1,13); Write(buffer);
  GotoXY(C2,13); Write(buffer);
  cons = mission->Consumables() / 3600;
  cons = (cons * 0.060666) + (cons * 0.308333) + (cons * 0.205833);
  sprintf(buffer,"%6d hrs",mission->Consumables() / 3600);
  GotoXY(C1,14); Write(buffer);
  sprintf(buffer,"%6.0f kg",cons);
  GotoXY(C2,14); Write(buffer);
  dry += cons;
  switch (mission->Rover()) {
    case 0:
         GotoXY(C1,15); Write("  None");
         sprintf(buffer,"%6.0f kg",(Double)0);
         GotoXY(C2,15); Write(buffer);
         break;
    case 1:
         GotoXY(C1,15); Write("  Mk I");
         dry += ROVER_MKI_WEIGHT;
         sprintf(buffer,"%6.0f kg",(Double)ROVER_MKI_WEIGHT);
         GotoXY(C2,15); Write(buffer);
         break;
    case 2:
         GotoXY(C1,15); Write(" Mk II");
         dry += ROVER_MKII_WEIGHT;
         sprintf(buffer,"%6.0f kg",(Double)ROVER_MKII_WEIGHT);
         GotoXY(C2,15); Write(buffer);
         break;
    case 3:
         GotoXY(C1,15); Write("Mk III");
         dry += ROVER_MKIII_WEIGHT;
         sprintf(buffer,"%6.0f kg",(Double)ROVER_MKIII_WEIGHT);
         GotoXY(C2,15); Write(buffer);
         break;
    }
  switch (mission->Lsep()) {
    case 0:
         GotoXY(C1,16); Write("  None");
         sprintf(buffer,"%6.0f kg",(Double)0);
         GotoXY(C2,16); Write(buffer);
         break;
    case 1:
         GotoXY(C1,16); Write(" ELSEP");
         sprintf(buffer,"%6.0f kg",(Double)ELSEP_WEIGHT);
         GotoXY(C2,16); Write(buffer);
         dry += ELSEP_WEIGHT;
         break;
    case 2:
         GotoXY(C1,16); Write(" ALSEP");
         sprintf(buffer,"%6.0f kg",(Double)ALSEP_WEIGHT);
         GotoXY(C2,16); Write(buffer);
         dry += ALSEP_WEIGHT;
         break;
    }
  switch (mission->Laser()) {
    case 0:
         GotoXY(C1,17); Write("    No");
         sprintf(buffer,"%6.0f kg",(Double)0);
         GotoXY(C2,17); Write(buffer);
         break;
    case 1:
         GotoXY(C1,17); Write("   Yes");
         sprintf(buffer,"%6.0f kg",(Double)LASER_WEIGHT);
         GotoXY(C2,17); Write(buffer);
         dry += LASER_WEIGHT;
         break;
    }
  sprintf(buffer,"%6.0f kg",dry + mission->DescentFuel());
  GotoXY(C2,18); Write(buffer);
  dry += pay;
  full = dry + mission->DescentFuel();
  deltaV = (mission->Model()->DescentIsp() * 9.80655) * log(full/dry);
  sprintf(buffer,"%6.0f m/s",deltaV);
  GotoXY(C2,19); Write(buffer);
  sprintf(buffer,"%6.0f kg",full);
  GotoXY(C2,21); Write(buffer);
  Flush();
  }

