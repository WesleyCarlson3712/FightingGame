#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include "character.h"
#include "game.h"
#include "misc.h"
#include "dialog.h"
using namespace std; 

int main() {

  srand(time(NULL));
  
  Game game;
  game.runGame();
 
}

#endif // MAIN_CPP


