#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
using namespace std;

class Character {
public:
  Character() {}
  Character(string name, int health, int speed, int damageMin, int damageMax) {
    this->name = name;
    this->health = health;
    this->speed = speed;
    this->damageMin = damageMin;
    this->damageMax = damageMax;
  }
  string name = "";
  int health = 0;
  int speed = 0;
  int damageMin = 0;
  int damageMax = 0;
  int turnThingie = 0;

  vector<vector<string>> returnCharacterContent(Character apponent) {
      vector<vector<string>> content = {
        {to_string(this->health),    "Health",     to_string(apponent.health)},
        {to_string(this->speed),     "Speed",      to_string(apponent.speed)},
        {to_string(this->damageMin), "Damage Min", to_string(apponent.damageMin)},
        {to_string(this->damageMax), "Damage Max", to_string(apponent.damageMax)}
      };
      return content;
    }


};

#endif // CHARACTER_H