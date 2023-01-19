#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "misc.h"
#include "dialog.h"
#include "character.h"
using namespace std;

class Game {
public:

  Game() : player("Human", 100, 8, 5, 35), apponent("Dragon", 125, 12, 10, 45) {}

  Character player;
  Character apponent;

  const int screanWidth = 40;
  vector<string> title = {player.name, "Stats", apponent.name};

  //-----------------------------------------------

  void runGame() {
    Dialog::displaystuff(title, player.returnCharacterContent(apponent), screanWidth);
    switch Dialog::options();
    //combat(player, apponent, screanWidth);
  }

  //-----------------------------------------------------------------

  void combat(Character attacker, Character &victim, int width) {
    int damage = Misc::randomNumber(attacker.damageMax, attacker.damageMin);
    victim.health -= damage;
    if(victim.health < 0)
      victim.health = 0;
    Dialog::takeDamage(attacker, victim, damage, width);
  }




};

#endif // GAME_H