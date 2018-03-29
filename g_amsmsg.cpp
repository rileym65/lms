#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsmsg.h"
#include "terminal.h"

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
  if (strcmp(seq->Message(),lastMessage) != 0) {
    GotoXY(x,y); printf("%s:",seq->Message());
    strcpy(lastMessage,seq->Message());
    }
  if (seq->Time() != lastSeqTime) {
    GotoXY(x+11,y);
    if (seq->Time() <= 0) {
      printf("    ");
      }
    else {
      i = seq->Time();
      if (i > 9999) i = 9999;
      printf("%4d",i);
      }
    lastSeqTime = seq->Time();
    }
  }

