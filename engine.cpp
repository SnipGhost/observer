//---------------------------------------------------------
// Project: Observer
// File: engine.cpp
//                                      (C) SnipGhost, 2016
//---------------------------------------------------------
#include "engine.h"
//---------------------------------------------------------
void Randomize() {
 long int ltime = time(NULL);
 int stime = (unsigned) ltime/2;
 srand(stime);    
}
//---------------------------------------------------------
void Init(int width, int height, int color, char *name) {
 initwindow(width, height, name, 200, 200); 
 setfillstyle(1, color);  
 floodfill(1, 1, 15);
}
//---------------------------------------------------------
void Close(void) {
 closegraph();
}
//---------------------------------------------------------
void Wait(void) {
 getch();     
}
//---------------------------------------------------------
void Clear(void) {
 cleardevice(); 
 setfillstyle(1, 0);  
 floodfill(1, 1, 15);   
}
//---------------------------------------------------------
void Buffer(void) {
 swapbuffers();     
}
//---------------------------------------------------------
void Write(char *text) {
 setcolor(15);
 outtext(text);     
}
//---------------------------------------------------------
char* IntToChr(int c) {
 char *ch;
 int num = c;
 int count = (num == 0) ? 1 : 0;
 while (num != 0) {
  count++;
  num /= 10;
 }
 ch = new char[count+1];
 int i = count-1;
 while (c != 0) {
  ch[i] = c%10+'0';
  i--;
  c /= 10;
 }
 ch[count] = 0;
 return ch;      
}
//---------------------------------------------------------
void PrintLog(const char *s1, ...) {
 va_list ap;
 va_start(ap, s1);
 for (const char* s=s1; s!=0; s=va_arg(ap,const char*))
  std::cout << s;
 std::cout << std::endl;
 va_end(ap);
}
//---------------------------------------------------------
SWorld::SWorld() {
 w = 200;
 h = 200;
 bcolor = 0;
 name = "Observer"; 
 Init(w, h, bcolor, name);               
}
SWorld::SWorld(int width, int height, 
               int clr, char *s) {
 w = width; 
 h = height;   
 bcolor = clr;
 name = s;
 Init(w, h, bcolor, name);       
}
//---------------------------------------------------------
SUnit::SUnit() {
 x = 0;
 y = 0;
 hp = 1;
 dp = 0;
 ep = 1;
 rp = 1;
 color = 15;
 ksize = 2;
 nteam = 1;                 
}
SUnit::SUnit(int xc, int yc,
      int health, 
      int damage, 
      int energy, 
      int radars,
      int colors,
      int size,
      int team) {
 x = xc;
 y = yc;
 hp = health;
 dp = damage;
 ep = energy;
 rp = radars;
 color = colors;
 ksize = size;
 nteam = team;                 
}
//---------------------------------------------------------
void SUnitD::Draw(void) {
 int r1 = 2, r2 = 4;
 setcolor(color);
 moveto(x-r1*ksize, y);
 lineto(x, y-r2*ksize);
 lineto(x+r1*ksize, y);
 lineto(x, y+r2*ksize);
 lineto(x-r1*ksize, y);
 setfillstyle(1, color);
 floodfill(x, y, color);
}
//---------------------------------------------------------
void SUnitT::Draw(void) {
 int r1 = 2, r2 = 2;
 setcolor(color);
 moveto(x-r2*ksize, y+r1*ksize);
 lineto(x, y-r1*ksize);
 lineto(x+r2*ksize, y+r1*ksize);
 lineto(x-r2*ksize, y+r1*ksize);
 setfillstyle(1, color);
 floodfill(x, y, color);
}
//---------------------------------------------------------
