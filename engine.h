//---------------------------------------------------------
// Project: Observer
// File: engine.h
//                                      (C) SnipGhost, 2016
//---------------------------------------------------------
#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
//---------------------------------------------------------
#include <iostream>
#include <fstream>
#include <stdarg.h>
#include <time.h>
#include <math.h>
#include <graphics.h>
//---------------------------------------------------------
void Randomize();
char* IntToChr(int c);
int ChrToInt(char *ch);
std::string IntToStr(int c);
void PrintLog(const char *s1, ...);
void PrintLog(std::string s1);
//---------------------------------------------------------
//=====================================
class SWorld {
 public:
  int w, h;   // width, height
  int bcolor; // bg color
  int tcolor; // text color
  char *name; // window name
  int cycles; // iterations
  int count;  // count of units
  int fpause; // pause
  //***************************
  SWorld();
  SWorld(int width, 
         int height, 
         int backgroundclr,
         int textclr,
         int iterations,
         int pause,
         int objcount,        
         const char *s);  
  //***************************
  void Init(void);
  void Close(void);
  void Wait(void);
  void Clear(void);
  void Buffer(void);
  void Write(char *text);
  void Delay();
};
//=====================================
class SUnit {
 public:
  int x, y;    // coordinates
  int vmax;    // max velocity
  int hp;      // health points
  int dp;      // damage points
  int ep;      // energy points
  int rp;      // radars points
  int color;   // object color
  int ksize;   // object size
  int nteam;   // team number
  //***************************
  virtual void Draw(void) = 0;
  void Move(int xp, int yp);
  //***************************
  SUnit();
  SUnit(
   int xc, int yc,
   int velocity,
   int health, 
   int damage, 
   int energy, 
   int radars,
   int colors,
   int size,
   int team
  );
};
//=====================================
class SUnitD: public SUnit {
 public:
  void Draw(void);
  //***************************
  SUnitD():SUnit() {};
  SUnitD(
   int xc, int yc,
   int velocity,
   int health, 
   int damage, 
   int energy, 
   int radars,
   int colors,
   int size,
   int team
  ): SUnit ( xc, yc, velocity, 
             health, damage, 
             energy, radars,
             colors, size, team
  ) {};
};
//=====================================
class SUnitT: public SUnit {
 public:
  void Draw(void);
  //***************************
  SUnitT():SUnit() {};
  SUnitT(
   int xc, int yc,
   int velocity,
   int health, 
   int damage, 
   int energy, 
   int radars,
   int colors,
   int size,
   int team
  ): SUnit ( xc, yc, velocity, 
             health, damage, 
             energy, radars,
             colors, size, team
  ) {};
};
//=====================================
class SUnitR: public SUnit {
 public:
  void Draw(void);
  //***************************
  SUnitR():SUnit() {};
  SUnitR(
   int xc, int yc,
   int velocity,
   int health, 
   int damage, 
   int energy, 
   int radars,
   int colors,
   int size,
   int team
  ): SUnit ( xc, yc, velocity, 
             health, damage, 
             energy, radars,
             colors, size, team
  ) {};
};
//=====================================
//---------------------------------------------------------
SWorld *LoadWorldFromFile(std::string path);
SUnit *LoadUnitFromFile(std::string path);
//---------------------------------------------------------
#endif // ENGINE_H_INCLUDED
//---------------------------------------------------------
