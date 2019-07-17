#include "header.h"

Boolean SelectFromMap(Double* latitude, Double* longitude) {
  int key;
  int cursorX;
  int cursorY;
  Double centerLat;
  Double centerLng;
  centerLat = *latitude;
  centerLng = *longitude;
  LoadMap(*latitude,*longitude,0);
  ClearScreen();
  Box(3,2,61,21);
  GotoXY(66,3); Write("Latitude:");
  GotoXY(66,6); Write("Longitude:");
  GotoXY(66,9); Write("Dist North:");
  GotoXY(66,12); Write("Dist East:");
  ShowMapData(*latitude,*longitude);
  GotoXY(2,10); Write("S");
  GotoXY(2,11); Write("O");
  GotoXY(2,12); Write("U");
  GotoXY(2,13); Write("T");
  GotoXY(2,14); Write("H");
  GotoXY(64,10); Write("N");
  GotoXY(64,11); Write("O");
  GotoXY(64,12); Write("R");
  GotoXY(64,13); Write("T");
  GotoXY(64,14); Write("H");
  GotoXY(31,23); Write("EAST");
  ShowMap();
  Flush();
  key = 0;
  cursorX = 0;
  cursorY = 0;
  ShowMapCursor(cursorX,cursorY);
  HideCursor(); Flush();
  while (key != 13 && key != 27) {
    key = Inkey();
    if (key == 10) key = 13;
    if (key == KEY_UP_ARROW) {
      HideMapCursor(cursorX,cursorY);
      cursorY--;
      *longitude -= CELL;
      ShowMapData(*latitude,*longitude);
      if (cursorY == -8) {
        cursorY++;
        centerLng -= CELL;
        LoadMap(centerLat,centerLng,0);
        ShowMap();
        }
      ShowMapCursor(cursorX,cursorY);
      }
    if (key == KEY_DOWN_ARROW) {
      HideMapCursor(cursorX,cursorY);
      cursorY++;
      *longitude += CELL;
      ShowMapData(*latitude,*longitude);
      if (cursorY == 8) {
        cursorY--;
        centerLng += CELL;
        LoadMap(centerLat,centerLng,0);
        ShowMap();
        }
      ShowMapCursor(cursorX,cursorY);
      }
    if (key == KEY_RIGHT_ARROW) {
      HideMapCursor(cursorX,cursorY);
      cursorX++;
      *latitude += CELL;
      ShowMapData(*latitude,*longitude);
      if (cursorX == 28) {
        cursorX--;
        centerLat += CELL;
        LoadMap(centerLat,centerLng,0);
        ShowMap();
        }
      ShowMapCursor(cursorX,cursorY);
      }
    if (key == KEY_LEFT_ARROW) {
      HideMapCursor(cursorX,cursorY);
      cursorX--;
      *latitude -= CELL;
      ShowMapData(*latitude,*longitude);
      if (cursorX == -28) {
        cursorX++;
        centerLat -= CELL;
        LoadMap(centerLat,centerLng,0);
        ShowMap();
        }
      ShowMapCursor(cursorX,cursorY);
      }
    }
  ShowCursor(); Flush();
  if (key == 13) return true;
  return false;
  }

