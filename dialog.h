#ifndef DIALOG_H
#define DIALOG_H

#include <iostream>
#include <iomanip>
#include <vector>
#include "misc.h"
#include "character.h"
using namespace std;

namespace Dialog {

  void drawLine(int width) {
    cout << setfill('-') << setw(width) << "-" << setfill(' ') << endl;
  }

  //-----------------------------------------------------------------------------------------

  void takeDamage(Character attacker, Character victim, int damage, int width) {
    drawLine(width);
    cout << attacker.name << " attacks " << victim.name << " and does " << damage << " damage.\n";
    drawLine(width);
  }

  //----------------------------------------------------------------------------------

  void displayStats(Character cLeft, Character cRight) {
    
    cout << cLeft.name << setw(35 - cLeft.name.length()) << cRight.name << endl;
    cout << "-----------------------------------\n";
    cout << "Health: " << cLeft.health << setw(27 - Misc::intSize(cLeft.health) - Misc::intSize(cRight.health))
         << "Health: " << cRight.health << endl;
    cout << "Speed: " << cLeft.speed << setw(28 - Misc::intSize(cLeft.speed) - Misc::intSize(cRight.speed))
         << "Speed: " << cRight.speed << endl;
    cout << "Damage Min: " << cLeft.damageMin << setw(23 - Misc::intSize(cLeft.damageMin) - Misc::intSize(cRight.damageMin))
         << "Damage Min: " << cRight.damageMin << endl;
    cout << "Damage Max: " << cLeft.damageMax << setw(23 - Misc::intSize(cLeft.damageMax) - Misc::intSize(cRight.damageMax))
         << "Damage Max: " << cRight.damageMax << endl;
    cout << "-----------------------------------\n";
  }

  //------------------------------------------------------------------------------------------------

  void centerText(string txt, int width) {
    int x = width / 2 + txt.length() / 2;
    cout << setw(x) << txt << endl;
    
  }
  //--------------------------------------------------------------------------------------------------

  void formatLine(vector<string> input, int width) {
    int c1 = (width / 3);
    int c2 = (width / 3) / 2 + (input[1].length() / 2);
    int c3 = (width) - (( width / 3 ) + c2 );
    cout << left << setw(width / 3) << input[0] 
         << setw(c2) << right << input[1] 
         << setw(c3) << input[2] << endl;
  }

  //-------------------------------------------------------------------------------
  void displaystuff(vector<string> title, vector<vector<string>> content, int width) {
    if(width < 30)
      width = 30;
    formatLine(title, width);
    drawLine(width);
    for(int i = 0; i < content.size(); i++) {
      formatLine(content[i], width);
      
    }
    drawLine(width);
  }
  
  int options(){
    vector<string> options = {"Attack", "Defend", "Run away"};
    for(int i = 0; i < options.size(); i++){
    cout << i + 1 <<  ": " << options[i] << endl;
    }
    cout << "Select an Action >> ";
    return Misc::getInt(1, options.size());
    
  }
}      
#endif // DIALOG_H


/*
Human          Stats         Dragon
-----------------------------------
100            Health           125
8              Speed             12
35           Damage Min          10
5            Damage Max          45
-----------------------------------
1: Attack
2: Defend
3: Run Away
Select an action >> 1
-----------------------------------
Human attacks Dragon and does 15 
damage.
-----------------------------------
Dragon attacks Human and does 51 
damage.
-----------------------------------

Human          Stats         Dragon
-----------------------------------
49             Health           110
8              Speed             12
35           Damage Min          10
5            Damage Max          45
-----------------------------------
1: Attack
2: Defend
3: Run Away
Select an action >> 3
-----------------------------------
Human fails to escape.
-----------------------------------
Dragon attacks Human and does 49 
damage.
-----------------------------------
            Game Over
*/