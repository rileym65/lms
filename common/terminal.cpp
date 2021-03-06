#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#ifdef MINGW
#include <windows.h>
#include <conio.h>
#endif

#ifndef MINGW
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
struct termios original;
#endif

#include "terminal.h"

typedef struct {
  const char* escape_sequence;
  int   value;
  } KEYDEF;

int esc_mode;
char esc_seq[80];
KEYDEF keys[] = {
  { "[A",          KEY_UP_ARROW                  },
  { "[B",          KEY_DOWN_ARROW                },
  { "[D",          KEY_LEFT_ARROW                },
  { "[C",          KEY_RIGHT_ARROW               },
  { "[2~",         KEY_INSERT                    },
  { "[3~",         KEY_DELETE                    },
  { "OH",          KEY_HOME                      },
  { "[H",          KEY_KP_HOME                   },
  { "[F",          KEY_KP_END                    },
  { "OF",          KEY_END                       },
  { "[5~",         KEY_PGUP                      },
  { "[6~",         KEY_PGDN                      },
  { "[1~",         KEY_KP_HOME                   },
  { "[4~",         KEY_KP_END                    },
  { "[E",          KEY_KP_5                      },
  { "[1;2A",       KEY_UP_ARROW|KEY_SHIFT_MOD    },
  { "[1;2B",       KEY_DOWN_ARROW|KEY_SHIFT_MOD  },
  { "[1;2D",       KEY_LEFT_ARROW|KEY_SHIFT_MOD  },
  { "[1;2C",       KEY_RIGHT_ARROW|KEY_SHIFT_MOD },
  { "[1;5A",       KEY_UP_ARROW|KEY_CTRL_MOD     },
  { "[1;5B",       KEY_DOWN_ARROW|KEY_CTRL_MOD   },
  { "[1;5D",       KEY_LEFT_ARROW|KEY_CTRL_MOD   },
  { "[1;5C",       KEY_RIGHT_ARROW|KEY_CTRL_MOD  },
  { "[1;3A",       KEY_UP_ARROW|KEY_ALT_MOD      },
  { "[1;3B",       KEY_DOWN_ARROW|KEY_ALT_MOD    },
  { "[1;3D",       KEY_LEFT_ARROW|KEY_ALT_MOD    },
  { "[1;3C",       KEY_RIGHT_ARROW|KEY_ALT_MOD   },
  { "[1;6A",       KEY_UP_ARROW|KEY_SHIFT_MOD|KEY_CTRL_MOD    },
  { "[1;6D",       KEY_LEFT_ARROW|KEY_SHIFT_MOD|KEY_CTRL_MOD  },
  { "[1;6A",       KEY_UP_ARROW|KEY_SHIFT_MOD|KEY_CTRL_MOD    },
  { "[1;6C",       KEY_RIGHT_ARROW|KEY_SHIFT_MOD|KEY_CTRL_MOD },
  { "[1;8B",       KEY_DOWN_ARROW|KEY_SHIFT_MOD|KEY_CTRL_MOD|KEY_ALT_MOD  },
  { "[1;8D",       KEY_LEFT_ARROW|KEY_SHIFT_MOD|KEY_CTRL_MOD|KEY_ALT_MOD  },
  { "[1;8A",       KEY_UP_ARROW|KEY_SHIFT_MOD|KEY_CTRL_MOD|KEY_ALT_MOD    },
  { "[1;8C",       KEY_RIGHT_ARROW|KEY_SHIFT_MOD|KEY_CTRL_MOD|KEY_ALT_MOD },
  { "OP",          KEY_F1                        },
  { "OQ",          KEY_F2                        },
  { "OR",          KEY_F3                        },
  { "OS",          KEY_F4                        },
  { "[15~",        KEY_F5                        },
  { "[17~",        KEY_F6                        },
  { "[18~",        KEY_F7                        },
  { "[19~",        KEY_F8                        },
  { "[20~",        KEY_F9                        },
  { "[21~",        KEY_F10                       },
  { "[23~",        KEY_F11                       },
  { "[24~",        KEY_F12                       },
  { "[1;2P",       KEY_F1|KEY_SHIFT_MOD          },
  { "[1;2Q",       KEY_F2|KEY_SHIFT_MOD          },
  { "[1;2R",       KEY_F3|KEY_SHIFT_MOD          },
  { "[1;2S",       KEY_F4|KEY_SHIFT_MOD          },
  { "[15;2~",      KEY_F5|KEY_SHIFT_MOD          },
  { "[17;2~",      KEY_F6|KEY_SHIFT_MOD          },
  { "[18;2~",      KEY_F7|KEY_SHIFT_MOD          },
  { "[19;2~",      KEY_F8|KEY_SHIFT_MOD          },
  { "[20;2~",      KEY_F9|KEY_SHIFT_MOD          },
  { "[21;2~",      KEY_F10|KEY_SHIFT_MOD         },
  { "[23;2~",      KEY_F11|KEY_SHIFT_MOD         },
  { "[24;2~",      KEY_F12|KEY_SHIFT_MOD         },
  { "O1;2P",       KEY_F1|KEY_SHIFT_MOD          },
  { "O1;2Q",       KEY_F2|KEY_SHIFT_MOD          },
  { "O1;2R",       KEY_F3|KEY_SHIFT_MOD          },
  { "O1;2S",       KEY_F4|KEY_SHIFT_MOD          },
  { "[1;5P",       KEY_F1|KEY_CTRL_MOD           },
  { "[1;5Q",       KEY_F2|KEY_CTRL_MOD           },
  { "[1;5R",       KEY_F3|KEY_CTRL_MOD           },
  { "[1;5S",       KEY_F4|KEY_CTRL_MOD           },
  { "[15;5~",      KEY_F5|KEY_CTRL_MOD           },
  { "[17;5~",      KEY_F6|KEY_CTRL_MOD           },
  { "[18;5~",      KEY_F7|KEY_CTRL_MOD           },
  { "[19;5~",      KEY_F8|KEY_CTRL_MOD           },
  { "[20;5~",      KEY_F9|KEY_CTRL_MOD           },
  { "[21;5~",      KEY_F10|KEY_CTRL_MOD          },
  { "[23;5~",      KEY_F11|KEY_CTRL_MOD          },
  { "[24;5~",      KEY_F12|KEY_CTRL_MOD          },
  { "O1;5P",       KEY_F1|KEY_CTRL_MOD           },
  { "O1;5Q",       KEY_F2|KEY_CTRL_MOD           },
  { "O1;5R",       KEY_F3|KEY_CTRL_MOD           },
  { "O1;5S",       KEY_F4|KEY_CTRL_MOD           },
  { "[1;3P",       KEY_F1|KEY_ALT_MOD            },
  { "[1;3Q",       KEY_F2|KEY_ALT_MOD            },
  { "[1;3R",       KEY_F3|KEY_ALT_MOD            },
  { "[1;3S",       KEY_F4|KEY_ALT_MOD            },
  { "[15;3~",      KEY_F5|KEY_ALT_MOD            },
  { "[17;3~",      KEY_F6|KEY_ALT_MOD            },
  { "[18;3~",      KEY_F7|KEY_ALT_MOD            },
  { "[19;3~",      KEY_F8|KEY_ALT_MOD            },
  { "[20;3~",      KEY_F9|KEY_ALT_MOD            },
  { "[21;3~",      KEY_F10|KEY_ALT_MOD           },
  { "[23;3~",      KEY_F11|KEY_ALT_MOD           },
  { "[24;3~",      KEY_F12|KEY_ALT_MOD           },
  { "O1;3P",       KEY_F1|KEY_ALT_MOD            },
  { "O1;3Q",       KEY_F2|KEY_ALT_MOD            },
  { "O1;3R",       KEY_F3|KEY_ALT_MOD            },
  { "O1;3S",       KEY_F4|KEY_ALT_MOD            },
  { "",                 0 },
  };

void ClrScr() {
#ifdef MINGW
  HANDLE hConsole;
  COORD coordScreen = {0,0};
  DWORD cCharsWritten;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD dwConSize;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  GetConsoleScreenBufferInfo(hConsole,&csbi);
  dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
  FillConsoleOutputCharacter(hConsole,(TCHAR)' ',dwConSize,coordScreen,&cCharsWritten);
  GetConsoleScreenBufferInfo(hConsole,&csbi);
  FillConsoleOutputAttribute(hConsole,csbi.wAttributes,dwConSize,coordScreen,&cCharsWritten);
  SetConsoleCursorPosition(hConsole,coordScreen);
#else
  printf("\e[H\e[2J");
#endif
  }

void GotoXY(int x, int y) {
#ifdef MINGW
  HANDLE hConsole;
  COORD coordScreen;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  coordScreen.X = x - 1;
  coordScreen.Y = y - 1;
  SetConsoleCursorPosition(hConsole,coordScreen);
#else
  printf("\e[%d;%dH",y,x);
#endif
  }

int KeyPressed() {
#ifdef MINGW
  if (kbhit()) return 1;
  return 0;
#else
  int c;
  fd_set rfds;
  struct timeval tv;
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  FD_ZERO(&rfds);
  FD_SET(0,&rfds);
  c = select(FD_SETSIZE,&rfds,NULL,NULL,&tv);
  return (c != 0) ? -1 : 0;
#endif
  }

void HideCursor() {
#ifdef MINGW
  HANDLE hConsole;
  CONSOLE_CURSOR_INFO cursor;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  cursor.dwSize = 100;
  cursor.bVisible = FALSE;
  SetConsoleCursorInfo(hConsole,&cursor);
#else
  printf("\E[?25l");
#endif
  }

void ShowCursor() {
#ifdef MINGW
  HANDLE hConsole;
  CONSOLE_CURSOR_INFO cursor;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  cursor.dwSize = 100;
  cursor.bVisible = TRUE;
  SetConsoleCursorInfo(hConsole,&cursor);
#else
  printf("\E[?25h");
#endif
  }

int Inkey() {
#ifdef MINGW
  Int32           c;
  unsigned char          key;
  c = 0;
  key = getch();
  c = key;
  if (key == 224 || key == 0) {
      key = getch();
      if (key == 72) c = KEY_UP_ARROW;
      if (key == 80) c = KEY_DOWN_ARROW;
      if (key == 75) c = KEY_LEFT_ARROW;
      if (key == 77) c = KEY_RIGHT_ARROW;
      if (key == 71) c = KEY_HOME;
      if (key == 73) c = KEY_PGUP;
      if (key == 79) c = KEY_END;
      if (key == 81) c = KEY_PGDN;
      if (key == 82) c = KEY_INSERT;
      if (key == 59) c = KEY_F1;     // F1
      if (key == 60) c = KEY_F2;     // F2
      if (key == 61) c = KEY_F3;     // F3
      if (key == 62) c = KEY_F4;     // F4
      if (key == 63) c = KEY_F5;     // F5
      if (key == 64) c = KEY_F6;     // F6
      if (key == 65) c = KEY_F7;     // F7
      if (key == 66) c = KEY_F8;     // F8
      if (key == 67) c = KEY_F9;     // F9
      if (key == 68) c = KEY_F10;     // F10
      }
  if (c == 10) c = 13;
  return c;
#else
  int i;
  int  c;
  char key;
  c = 0;
  while (c == 0) {
    read(0,&key,1);
    c = key;
    if (esc_mode > 0) {
      esc_seq[esc_mode-1] = c;
      esc_seq[esc_mode] = 0;
      esc_mode++;
      if (c >= 'A' && c <= 'Z' && c != 'O') esc_mode = 0;
      if (c >= 'a' && c<= '~') esc_mode = 0;
      if (esc_mode > 10) esc_mode = 0;
      c = 0;
      if (esc_mode == 0) {
        i = 0;
        while (keys[i].value != 0 && c == 0) {
          if (strcmp(keys[i].escape_sequence, esc_seq) == 0) c = keys[i].value;
          i++;
          }
        if (c == 0) printf("Unknown key: %s\n",esc_seq);
        }
      }
    else if (c == 27 && KeyPressed()) {
      esc_mode = 1;
      esc_seq[0] = 0;
      c = 0;
      }
    }
  return c;
#endif
  }

void Write(const char* message) {
  printf("%s",message);
  }

void WriteLn(const char* message) {
  printf("%s%s",message,LE);
  }

void WriteCh(char chr) {
  printf("%c",chr);
  }

int OpenTerminal() {
#ifdef MINGW
#else
  struct termios terminal;
  esc_mode = 0;
  tcgetattr(0, &terminal);
  original = terminal;
  terminal.c_lflag &= ~ICANON;
  terminal.c_lflag &= ~ECHO;
  if (tcsetattr(0, TCSANOW, &terminal) != 0) return -1;
#endif
  return 0;
  }

void CloseTerminal() {
#ifdef MINGW
  ShowCursor();
#else
  tcsetattr(0, TCSANOW, &original);
#endif
  }

