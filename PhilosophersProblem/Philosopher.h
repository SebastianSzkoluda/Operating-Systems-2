#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <atomic>
#include "Fork.h"


using namespace std;

enum State{
  Think,Eat,WaitForForks
};

class Philosopher
{
    public:
      Fork* leftFork;
      Fork* rightFork;
      volatile bool running;
      int currentProgress;
      std::atomic<State> state;
      int lvlOfStuffed;
      int phiId;
        Philosopher(int phiIdC,Fork* leftForkC,Fork* rightForkC);
        ~Philosopher();
        void start();
        int GetphiId() { return phiId; }
        void SetphiId(int val) { phiId = val; }
        void takeForks();
        void releaseForks();
        int randomTime();
        void waiting(int time);
        int getCurrentProgress(){return currentProgress; }
        bool getRunning(){return running;}
        void setRunning(bool runningSet){ running = runningSet; }
        void breakRunning();


};
