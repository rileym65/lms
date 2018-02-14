#ifndef _TERMINAL_H
#define _TERMINAL_H

#define KEY_F1             0x1001
#define KEY_F2             0x1002
#define KEY_F3             0x1003
#define KEY_F4             0x1004
#define KEY_F5             0x1005
#define KEY_F6             0x1006
#define KEY_F7             0x1007
#define KEY_F8             0x1008
#define KEY_F9             0x1009
#define KEY_F10            0x1010
#define KEY_F11            0x1011
#define KEY_F12            0x1012
#define KEY_SHIFT_MOD      0x0100
#define KEY_CTRL_MOD       0x0200
#define KEY_ALT_MOD        0x0400
#define KEY_UP_ARROW       0x2001
#define KEY_DOWN_ARROW     0x2002
#define KEY_LEFT_ARROW     0x2003
#define KEY_RIGHT_ARROW    0x2004
#define KEY_INSERT         0x2005
#define KEY_DELETE         0x2006
#define KEY_HOME           0x2007
#define KEY_END            0x2008
#define KEY_PGUP           0x2009
#define KEY_PGDN           0x200a
#define KEY_KP_HOME        0x200b
#define KEY_KP_END         0x200c
#define KEY_KP_5           0x200d

extern void CloseTerminal();
extern void ClrScr();
extern void GotoXY(int x, int y);
extern void HideCursor();
extern int  Inkey();
extern int  KeyPressed();
extern int  OpenTerminal();
extern void ShowCursor();

#endif

