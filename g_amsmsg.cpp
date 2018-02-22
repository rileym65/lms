#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsmsg.h"
#include "terminal.h"

G_AmsMessage::G_AmsMessage(Int8 x,Int8 y,Boolean f) :
  Gauge(x, y, f) {
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
  if (strcmp(seq->Message(),lastMessage) != 0) {
    GotoXY(x,y); printf("%s",seq->Message());
    strcpy(lastMessage,seq->Message());
    }
  if (seq->Time() != lastSeqTime) {
    GotoXY(x+11,y);
    if (seq->Time() == 0) {
      printf("    ");
      }
    else {
      printf("%4d",seq->Time());
      }
    lastSeqTime = seq->Time();
    }
  }

