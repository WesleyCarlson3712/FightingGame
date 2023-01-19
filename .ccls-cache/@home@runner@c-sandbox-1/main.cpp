#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "character.h"
using namespace std; 



int randomNumber(int max, int min){
  return rand() % (max + 1 - min) + (min - 1);
}

void attack(Character &victim, Character &attacker) {
  int damageDealt = randomNumber(attacker.damageMax, attacker.damageMin);
  victim.health -= damageDealt;
//  cout << setw(15) << attacker.name << " attacks " << victim.name << " and does " << damageDealt << " damage." << endl;
}


int main() {
  
  srand(time(NULL));
  
  Character player;
  Character monster;
  player.name = "human";
  player.health = 100;
  player.speed = 10;
  player.damageMin = 5;
  player.damageMax = 35;
  monster.name = "dragon";
  monster.health = 125;
  monster.speed = 6;
  monster.damageMin = 10;
  monster.damageMax = 45;
  
  }
}