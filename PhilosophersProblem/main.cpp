#include <vector>
#include <iostream>
#include <ncurses.h>
#include "Window.h"

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    Fork** forks = new Fork*[5];
    Philosopher** philosophers = new Philosopher*[5];
    for(int i=0;i<5;i++){
      forks[i] = new Fork(i);
    }
    for(int i=0;i<5;i++){
    if(i == 4){
      philosophers[i] = new Philosopher(i, forks[4], forks[0]);
      break;
    }
      philosophers[i] = new Philosopher(i, forks[i], forks[i+1]);
    }


    std::thread threads[5];

    for(int i=0;i<5;i++){
      threads[i] = std::thread(&Philosopher::start, philosophers[i]);
    }

    Window win = Window();
    win.startWindow(philosophers,forks);
    for(int i=0;i<5;i++){
      philosophers[i]->breakRunning();
    }
    for(int i=0;i<5;i++){
      threads[i].join();
    }
    clear();
    mvprintw(0,0,"Main end!");
    refresh();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    endwin();
    return 0;
}
