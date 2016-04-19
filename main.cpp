//---------------------------------------------------------
// Project: Observer
// File: main.cpp
//                                      (C) SnipGhost, 2016
//---------------------------------------------------------
#include "engine.h"
using namespace std;
//---------------------------------------------------------
int main(int argc, char *argv[])
{ 
 SWorld *World;
 SUnit **Unit;
 Randomize();
 //========================================================
 World = LoadWorldFromFile("data/test/world.txt");
 //========================================================
 Unit = new SUnit *[World->count];
 PrintLog("Create "+IntToStr(World->count)+" objects ...");
 for (int i = 0; i < World->count; i++) {
  string s = "data/test/unit"+IntToStr(i+1)+".txt";
  Unit[i] = LoadUnitFromFile(s);
 }
 PrintLog("Creating objects successfully completed", 0);
 //========================================================
 World->Write("Press any key to start ...");
 World->Wait();
 //========================================================
 int c = World->cycles;
 if (argc > 1) c = ChrToInt(argv[1]);
 PrintLog("Run for " + IntToStr(c) + " iterations");
 //========================================================
 while (c > 0) {
  c--;
  World->Clear();
  for (int i = 0; i < World->count; i++) {
   Unit[i]->Move(300-i*40+rand()%40, 100+i*40+rand()%40);
   Unit[i]->Draw();
  }
  World->Buffer();
  World->Delay();
 } 
 //========================================================
 World->Clear(); 
 World->Write("Press any key to exit ...");
 World->Buffer();
 World->Wait();
 PrintLog("Simulation stop", 0);
 //========================================================
 World->Close();
 for (int i = 0; i < World->count; i++) delete Unit[i];
 delete[] Unit;
 delete World;
 return 0;
}
//---------------------------------------------------------
