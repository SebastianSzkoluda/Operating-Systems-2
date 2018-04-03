#include "Window.h"
#include <pthread.h>
#include <ncurses.h>
#include <iostream>
#include <string>


Window::Window(){

  initscr();
  noecho();
  curs_set(0);
  start_color();
  init_pair(1,COLOR_RED, COLOR_BLACK);
  init_pair(2,COLOR_GREEN, COLOR_BLACK);
  init_pair(4,COLOR_BLUE, COLOR_BLACK);
  init_pair(3,COLOR_WHITE, COLOR_BLACK);
  init_pair(5,COLOR_YELLOW, COLOR_BLACK);
  bkgd(COLOR_PAIR(3));


}
Window::~Window(){
  endwin();
}
void Window::draw(){

  for(int i=0;i<5;i++){
    mvprintw(philoY[i],philoX[i],"%d",philoState[i]);
    move(forkY[i],forkX[i]);
    addch(forkState[i]);
  }
}
void Window::startWindow(Philosopher** philosophersW, Fork** forksW){

  draw();
  int c;
nodelay(stdscr, TRUE);
for(;;){
  if((c = getch())!=27){
    for(int i=0;i<5;i++){
   State s = philosophersW[i]->state;
    if(s == Eat){

          attron(COLOR_PAIR(4));
          mvprintw(philoY[i],philoX[i],"%d",philoState[i]);
          attroff(COLOR_PAIR(4));

    }
    else if(s == Think){
      attron(COLOR_PAIR(5));
      mvprintw(philoY[i],philoX[i],"%d",philoState[i]);
      attroff(COLOR_PAIR(5));
    }
    else{
      mvprintw(philoY[i],philoX[i],"%d",philoState[i]);
    }
    drawProgressBar(s,philosophersW[i]->currentProgress,i);
  for(int i=0;i<5;i++){
    ForkInUse(i,forksW[i]->getIsFree());
  }



  timeout(250);
  }
}
else {
  return;
}
}
}
void Window::ForkInUse(int forkId,bool isFree){

  move(forkY[forkId],forkX[forkId]);

  if(!isFree){
    attron(COLOR_PAIR(1));
  }
  else{
    attron(COLOR_PAIR(2));
  }

  addch(forkState[forkId]);


  attroff(COLOR_PAIR(2));
  attroff(COLOR_PAIR(1));



  }


void Window::drawProgressBar(State s, int progressSteps, int phiId){

    if(s == Eat ){
      mvprintw(12+phiId,0,"Filozof numer: %d jest w trakcie jedzenia: %d%s",phiId+1,10*(progressSteps+1),"%");
      attron(COLOR_PAIR(4));

    }
    else if(s == Think){
      mvprintw(12+phiId,0,"Filozof numer: %d jest w trakcie myslenia: %d%s",phiId+1,10*(progressSteps+1),"%");
      attron(COLOR_PAIR(5));
    }
    else if(s == WaitForForks){
      mvprintw(12+phiId,0,"Filozof numer: %d czeka na widelce",phiId+1);
      refresh();
    }
    clrtoeol();
    mvprintw(12+phiId,49,"[");
    for(int i = 0;i<progressSteps+1;i++){
      if(s == WaitForForks)
        break;
      mvprintw(12+phiId,50+i,"+");

    }
    mvprintw(12+phiId,60,"]");
    attroff(COLOR_PAIR(4));
    attroff(COLOR_PAIR(5));

    clrtoeol();
    attron(COLOR_PAIR(1));
    move(19,0);
    addch('/');
    attron(COLOR_PAIR(3));
    printw(" :  Wziety widelec");

    attron(COLOR_PAIR(2));
    move(20,0);
    addch('/');
    attron(COLOR_PAIR(3));
    printw(" :  Wolny widelec");

    attron(COLOR_PAIR(5));
    move(21,0);
    addch('5');
    attron(COLOR_PAIR(5));
    printw(" :  Filozof mysli");

    attron(COLOR_PAIR(4));
    move(22,0);
    addch('5');
    attron(COLOR_PAIR(4));
    printw(" :  Filozof je");

    attron(COLOR_PAIR(3));
    move(23,0);
    addch('5');
    attron(COLOR_PAIR(3));
    printw(" :  Filozof czeka na widelce");
}
