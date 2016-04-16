//---------------------------------------------------------
// Project: Observer
// File: main.cpp
//                                      (C) SnipGhost, 2016
//---------------------------------------------------------
#include "engine.h"
//---------------------------------------------------------
int main(int argc, char *argv[])
{ 
 SWorld *World;
 SUnit **Unit;
 Randomize();
 //========================================================
 World = LoadWorldFromFile("data/test/world.txt");
 //========================================================
 const int count = World->count;
 Unit = new SUnit *[count];
 PrintLog("Create ", IntToChr(count), " objects ...", 0);
 for (int i = 0; i < count; i++) {
  std::string s = "data/test/unit"+IntToStr(i+1)+".txt";
  Unit[i] = LoadUnitFromFile(s);
 }
 PrintLog("Creating objects successfully completed", 0);
 //========================================================
 World->Write("Press any key to start ...");
 World->Wait();
 //========================================================
 int c = World->cycles;
 if (argc > 1) c = ChrToInt(argv[1]);
 PrintLog("Run for ", IntToChr(c), " iterations", 0);
 //========================================================
 while (c > 0) {
  c--;
  World->Clear();
  for (int i = 0; i < count; i++) {
   Unit[i]->x += (rand()%3 - rand()%3);
   Unit[i]->y += (rand()%3 - rand()%3);
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
 for (int i = 0; i < count; i++) delete Unit[i];
 delete[] Unit;
 delete World;
 return 0;
}
//---------------------------------------------------------
