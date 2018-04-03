#include <vector>
#include "Philosopher.h"

using namespace std;

class Window
{
public:
  Window();
  ~Window();
  void draw();
  void startWindow(Philosopher** philosophersW, Fork** forksW);
  void ForkInUse(int forkId,bool isFree);
  void drawProgressBar(State s, int progressSteps, int phiId);
private:
  int philospoherId;
  int forkId;
  int philoState[5]={1,2,3,4,5};
  int philoY[5]={3,6,10,10,6};
  int philoX[5]={30,38,35,25,22};
  char forkState[5]={'/','\\','/','|','\\'};
  int forkY[5]={4,4,8,10,8};
  int forkX[5]={24,36,37,30,23};


};
