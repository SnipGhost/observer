//---------------------------------------------------------
// Project: Observer
// File: engine.cpp
//                                      (C) SnipGhost, 2016
//---------------------------------------------------------
#include "engine.h"
//---------------------------------------------------------
// GENERAL FUNCTIONS
//---------------------------------------------------------
void Randomize() {
 long int ltime = time(NULL);
 int stime = (unsigned) ltime/2;
 srand(stime);    
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
 if (c == 0) ch[0] = '0';
 while (c != 0) {
  ch[i] = c%10 + '0';
  i--;
  c /= 10;
 }
 ch[count] = 0;
 return ch;      
}
//---------------------------------------------------------
int ChrToInt(char *ch) {
 int c = 0;
 int count = strlen(ch);
 for (int i = 0; i < count; i++) {
  int x = ch[i] - '0';
  int a = count - i;
  while (a > 1) {
   x *= 10;
   a--;
  }
  c += x;
 }
 return c;
}
//---------------------------------------------------------
std::string IntToStr(int c) {
 std::string s = "";
 if (c == 0) s += "0";
 while (c > 0) {
  s += char(c%10 + '0');
  c /= 10;
 }
 return s;            
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
SWorld *LoadWorldFromFile(std::string path) {
 std::ifstream fin;
 fin.open(path.c_str());
 int w, h, bg, tcolor, i, p, cnt;
 std::string name;
 fin >> w;
 fin >> h;
 fin >> bg;
 fin >> tcolor;
 fin >> i;
 fin >> p;
 fin >> cnt;
 fin >> name;
 fin.close();
 PrintLog("Try to load world from ", path.c_str(), 0);
 return (new SWorld(w,h,bg,tcolor,i,p,cnt,name.c_str()));
}
//---------------------------------------------------------
SUnit *LoadUnitFromFile(std::string path) {
 std::ifstream fin;
 fin.open(path.c_str());
 int x, y;
 int hp;
 int dp;
 int ep;
 int rp;
 int c;
 int k;
 int n;
 int t;
 fin >> t;
 fin >> x >> y >> hp >> dp >> ep >> rp;
 fin >> c >> k >> n;
 fin.close();
 PrintLog("Try to load unit from ", path.c_str(), 0);
 if (t==0) return (new SUnitD(x,y,hp,dp,ep,rp,c,k,n));
 if (t==1) return (new SUnitT(x,y,hp,dp,ep,rp,c,k,n));
 if (t==3) return (new SUnitR(x,y,hp,dp,ep,rp,c,k,n));
 return 0;
}
//---------------------------------------------------------
// SWORLD CLASS FUNCTIONS
//---------------------------------------------------------
SWorld::SWorld() {
 w = 200;
 h = 200;
 bcolor = 0;
 name = "Observer"; 
 Init();               
}
SWorld::SWorld(int width, 
               int height, 
               int backgroundclr, 
               int textclr, 
               int iterations, 
               int pause, 
               int objcount, 
               const char *s) {
 w = width; 
 h = height;   
 bcolor = backgroundclr;
 tcolor = textclr;
 cycles = iterations;
 fpause = pause;
 count = objcount;
 name = strdup(s);
 int c = strlen(name);
 while (c > 0) { if (name[c] == '_') {name[c] = ' ';}c--;}
 Init();       
}
//---------------------------------------------------------
void SWorld::Init() {
 initwindow(w, h, name, 200, 200); 
 setfillstyle(1, bcolor);  
 floodfill(1, 1, 15);
 PrintLog("Window initialized", 0);
}
//---------------------------------------------------------
void SWorld::Close(void) {
 closegraph();
 PrintLog("Window destructed", 0);
}
//---------------------------------------------------------
void SWorld::Wait(void) {
 getch();     
}
//---------------------------------------------------------
void SWorld::Clear(void) {
 cleardevice(); 
 setfillstyle(1, bcolor);  
 floodfill(1, 1, 15);   
}
//---------------------------------------------------------
void SWorld::Buffer(void) {
 swapbuffers();     
}
//---------------------------------------------------------
void SWorld::Write(char *text) {
 setfillstyle(1, bcolor);  
 setcolor(tcolor);
 outtext(text);
 PrintLog("Window message: \"", text, "\"", 0);     
}
//---------------------------------------------------------
void SWorld::Delay() {
 Sleep(fpause);
}
//---------------------------------------------------------
// SUNIT CLASS FUNCTIONS
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
 PrintLog("Unit ", IntToChr(nteam+1), " initialized", 0);           
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
 PrintLog("Unit ", IntToChr(nteam+1), " initialized", 0);                  
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
void SUnitR::Draw(void) {
 int r1 = 2, r2 = 2;
 setcolor(color);
 moveto(x-r2*ksize, y-r1*ksize);
 lineto(x+r2*ksize, y-r1*ksize);
 lineto(x+r2*ksize, y+r1*ksize);
 lineto(x-r2*ksize, y+r1*ksize);
 lineto(x-r2*ksize, y-r1*ksize);
 setfillstyle(1, color);
 floodfill(x, y, color);
}
//---------------------------------------------------------
