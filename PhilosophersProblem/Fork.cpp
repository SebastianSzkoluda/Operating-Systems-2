#include "Fork.h"
#include <iostream>

using namespace std;

Fork::Fork(int id)
{
    this->Fid = id;
    this->isFree = true;
}

Fork::~Fork()
{
    //dtor
}
