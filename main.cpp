//---------------------------------------------------------
// Project: Observer
// File: main.cpp
//                                      (C) SnipGhost, 2016
//---------------------------------------------------------
#include <windows.h>
#include "engine.h"
//---------------------------------------------------------
#define OBJCOUNT 6     // count of simulated objects
#define NFDPAUSE 30    // next frame display pause (mSec)
//---------------------------------------------------------
SUnit *Unit[OBJCOUNT]; // global list of objects
//---------------------------------------------------------
int main()
{
 Randomize(); // Randomize programm
 //========================================================
 Init(500, 500, 0, "Project: Observer");
 PrintLog("Window initialized", 0);
 //========================================================
 PrintLog("Create OBJCOUNT SUinit objects ...", 0);
 for (int i = 0; i < 3; i++) {
  Unit[i] = new SUnitD(200+i*40,200,1,1,1,5,i+8,4,i);
  PrintLog("Unit ", IntToChr(i+1), " initialized", 0);
 }
 for (int i = 3; i < OBJCOUNT; i++) {
  Unit[i] = new SUnitT(200+(i-3)*40,240,1,1,1,5,i+8,4,i);
  PrintLog("Unit ", IntToChr(i+1), " initialized", 0);
 }  
 PrintLog("Creating objects successfully completed", 0);
 //========================================================
 Write("Press any key to start...");
 Wait();
 //========================================================
 int count = 999;
 while (count > 0) {
  count--;
  Clear();
  for (int i = 0; i < OBJCOUNT; i++) {
   Unit[i]->x += (rand()%3 - rand()%3);
   Unit[i]->y += (rand()%3 - rand()%3);
   Unit[i]->Draw();
  }
  Buffer();
  Sleep(NFDPAUSE);
 } 
 //========================================================
 Clear(); 
 Write("Press any key to exit...");
 Buffer();
 Wait();
 //========================================================
 Close();
 for (int i = 0; i < OBJCOUNT; i++) delete Unit[i];
 return 0;
}
//---------------------------------------------------------
