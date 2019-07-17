#include "header.h"

void GetRegion() {
  int key;
  int top;
  int line;
  int count;
  int len;
  char temp[64];
  UInt32 i;
  HideCursor();
  Box(20,2,40,20);
  top = 0;
  i = 0;
  count = 0;
  while (i < numCategories && count < 17) {
    GotoXY(26, 4+i); Write(categories[top+i]);
    i++;
    count++;
    }
  key = 0;
  line = 0;
  GotoXY(36,3); Write("Category:"); Flush();
  GotoXY(21,4+line); Write("--->"); Flush();
  while (key != 13 && key != 27) {
    key = Inkey();
    if (key == 10) key = 13;
    if (key == KEY_UP_ARROW) {
      GotoXY(21,4+line); Write("    "); Flush();
      line--;
      if (line < 0) {
        line = 0;
        if (top > 0) top--;
        i = 0;
        count = 0;
        while (i < numCategories && count < 17) {
          strcpy(temp, categories[top+i]);
          while (strlen(temp) < 20) strcat(temp, " ");
          GotoXY(26, 4+i); Write(temp);
          i++;
          count++;
          }
        }
      GotoXY(21,4+line); Write("--->"); Flush();
      }
    if (key == KEY_DOWN_ARROW) {
      GotoXY(21,4+line); Write("    "); Flush();
      line++;
      if (line >= count) {
        if ((UInt32)(line + top) < numCategories) {
          line--;
          top++;
          i = 0;
          count = 0;
          while (i < numCategories && count < 17) {
            strcpy(temp, categories[top+i]);
            while (strlen(temp) < 20) strcat(temp, " ");
            GotoXY(26, 4+i); Write(temp);
            i++;
            count++;
            }
          }
        else
          line--;
        }
      GotoXY(21,4+line); Write("--->"); Flush();
      }
    }
  if (key == 27) return;
  numSelections = 0;
  for (i=0; i<numFeatures; i++) {
    len = strlen(categories[top+line]);
    if (strncasecmp(features[i].name,categories[top+line],len) == 0)
      selections[numSelections++] = i;
    }
  top = 0;
  key = 0;
  line = 0;
  count = (numSelections < 18) ? numSelections : 18;
  ShowSelections(top, count);
  GotoXY(4,3+line); Write("--->"); Flush();
  while (key != 13 && key != 27) {
    key = Inkey();
    if (key == 10) key = 13;
    if (key == KEY_UP_ARROW) {
      GotoXY(4,3+line); Write("    "); Flush();
      line--;
      if (line < 0) {
        top--;
        line = 0;
        if (top < 0) top = 0;
        count = numSelections - top;
        if (count > 18) count = 18;
        ShowSelections(top, count);
        }
      GotoXY(4,3+line); Write("--->"); Flush();
      }
    if (key == KEY_DOWN_ARROW) {
      GotoXY(4,3+line); Write("    "); Flush();
      line++;
      if (line >= count) {
        line--;
        top++;
        count = 18;
        if (top + count >= numSelections) {
          top--;
          count = numSelections - top;
          if (count > 18) count = 18;
          }
        ShowSelections(top, count);
        }
      GotoXY(4,3+line); Write("--->"); Flush();
      }
    if (key == KEY_PGDN) {
      GotoXY(4,3+line); Write("    "); Flush();
      top += 18;
      line = 0;
      count = 18;
      if (top + count >= numSelections) {
        top = numSelections - 18;
        if (top < 0) top = 0;
        }
      ShowSelections(top, count);
      GotoXY(4,3+line); Write("--->"); Flush();
      }
    if (key == KEY_PGUP) {
      GotoXY(4,3+line); Write("    "); Flush();
      top -= 18;
      if (top < 0) top = 0;
      count = 18;
      if (count >= numSelections) count = numSelections;
      ShowSelections(top, count);
      GotoXY(4,3+line); Write("--->"); Flush();
      }
    }
  if (key == 13) {
    mission->Region(features[selections[line+top]].name);
    mission->TargetLongitude(features[selections[line+top]].longitude);
    mission->TargetLatitude(features[selections[line+top]].latitude);
    }

  ShowCursor();
  }

