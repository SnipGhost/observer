//---------------------------------------------------------
// Project: Observer
// File: engine.h
//                                      (C) SnipGhost, 2016
//---------------------------------------------------------
#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
//---------------------------------------------------------
#include <graphics.h>
#include <iostream>
#include <stdarg.h>
#include <time.h>
//---------------------------------------------------------
void Randomize();
void Init(int width, int height, int color, char *name);
void Close(void);
void Wait(void);
void Clear(void);
void Buffer(void);
void Write(char *text);
char* IntToChr(int c);
void PrintLog(const char *s1, ...);
//---------------------------------------------------------
class SWorld {
 public:
  int w, h;   // window width
  int bcolor; // window height
  char *name; // window name
  SWorld();
  SWorld(int width, 
         int height, 
         int background,
         char *s);      
};
//=====================================
class SUnit {
 public:
  int x, y;    // coordinates
  int hp;      // health points
  int dp;      // damage points
  int ep;      // energy points
  int rp;      // radars points
  int color;   // object color
  int ksize;   // object size
  int nteam;   // team number
  //***************************
  virtual void Draw(void) = 0;
  //***************************
  SUnit();
  SUnit(
   int xc, int yc,
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
   int health, 
   int damage, 
   int energy, 
   int radars,
   int colors,
   int size,
   int team
  ): SUnit ( xc, yc,  
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
   int health, 
   int damage, 
   int energy, 
   int radars,
   int colors,
   int size,
   int team
  ): SUnit ( xc, yc,  
             health, damage, 
             energy, radars,
             colors, size, team
  ) {};
};
//=====================================
//---------------------------------------------------------
#endif // ENGINE_H_INCLUDED
//---------------------------------------------------------
