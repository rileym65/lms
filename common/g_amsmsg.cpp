#include <string.h>
#include "types.h"
#include "gauge.h"
#include "g_amsmsg.h"
#include "terminal.h"
#include "common.h"

G_AmsMessage::G_AmsMessage(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 15;
  height = 1;
  Reset();
  }

G_AmsMessage::~G_AmsMessage() {
  }

void G_AmsMessage::Reset() {
  strcpy(lastMessage," ");
  lastSeqTime = -9999;
  }

void G_AmsMessage::Display() {
  }

void G_AmsMessage::Update() {
  Int32 i;
  char buffer[32];
  if (strcmp(seq->Message(),lastMessage) != 0) {
    GotoXY(x,y); sprintf(buffer,"%s:",seq->Message()); Write(buffer);
    strcpy(lastMessage,seq->Message());
    }
  if (seq->Time() != lastSeqTime) {
    GotoXY(x+11,y);
    if (seq->Value() < 0) {
      if (seq->Time() <= 0) {
        Write("    ");
        }
      else {
        i = seq->Time();
        if (i > 9999) i = 9999;
        sprintf(buffer,"%4d",i); Write(buffer);
        }
      }
    else {
      i = seq->Value();
      if (i > 9999) i = 9999;
      sprintf(buffer,"%4d",i); Write(buffer);
      }
    lastSeqTime = seq->Time();
    }
  }

