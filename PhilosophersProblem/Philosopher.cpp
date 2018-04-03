#include "Philosopher.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

Philosopher::Philosopher(int phiId,Fork* leftFork,Fork* rightFork)
{
  this->currentProgress = 0;
  this->phiId = phiId;
  this->leftFork = leftFork;
  this->rightFork = rightFork;

}
Philosopher::~Philosopher(){

}
void Philosopher::start()
{
  this->running = true;
            while(running){

              int thinkingTime = randomTime();
              waiting(thinkingTime);
              state = WaitForForks;
              takeForks();
              state = Eat;
              int eatingTime = randomTime();
              waiting(eatingTime);
              releaseForks();
              state = Think;


          }
}
void Philosopher::takeForks(){
  if(phiId == 1){
    leftFork->take();
    rightFork->take();
  }
  else{
    rightFork->take();
    leftFork->take();
  }


}
void Philosopher::releaseForks(){

  if(phiId == 1){
    rightFork->release();
    leftFork->release();
  }
  else{
    leftFork->release();
    rightFork->release();
  }



}
int Philosopher::randomTime(){
  return (4000 + rand()%4000)/10;

}
void Philosopher::waiting(int time){
  for(currentProgress = 0; currentProgress < 10; currentProgress++){
  std::this_thread::sleep_for(std::chrono::milliseconds(time));
}
currentProgress=0;
}
void Philosopher::breakRunning(){
  running = false;
}
