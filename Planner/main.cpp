#define MAIN

#include "header.h"

int main(int argc, char** argv) {
  char buffer[256];
  FILE* file;
  UInt32 i;
  int key;
  map = new Map();
  features = map->Features();
  numFeatures = map->NumFeatures();
  LoadCategories();
  OpenTerminal();
  key = 0;
  while (key != '3') {
    MainMenu();
    key = 0;
    while (key != '1' && key != '2' && key != '3') {
      key = Inkey();
      if (key == 27) key = '3';
      }
    if (key == '1') {
      mission = new Mission();
      MissionEditor();
      }
    if (key == '2') {
      Box(20,10,40,7);
      GotoXY(31,12); Write("Load Mission From:");
      if (Input(30,14,buffer,false)) {
        strcat(buffer,".msn");
        file = fopen(buffer,"r");
        if (file == NULL) {
          Box(30,11,20,5);
          GotoXY(33, 13); Write("File not found"); Flush();
          key = 0;
          HideCursor(); Flush();
          while (key == 0) key = Inkey();
          ShowCursor(); Flush();
          }
        else {
          mission = new Mission();
          mission->Load(file);
          fclose(file);
          MissionEditor();
          }
        }
      }
    }

  GotoXY(1,25);
  CloseTerminal();
  for (i=0; i<numCategories; i++)
    free(categories[i]);
  free(categories);
  }

