#ifndef MISC_H
#define MISC_H

#include <iostream>
#include <iomanip>
using namespace std;

namespace Misc {
  int getInt(int min, int max) {
    int number = 0;
    bool invalid = false;
    
    do{
        cin >> number;
        invalid = (number < min || number > max || cin.fail());

        if(invalid) {
            cout << "Invalad Input" << endl;
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Select an Action >> ";
        }

    } while(invalid);

    return number;
  }
  //-------------------------------------------------------------------
  int intSize(int inputNum) {
    int i = 0;
    while(inputNum > 0){
      inputNum /= 10;
      i++;
    }
    return i;
  }
  //----------------------------------------------------------------------
  int randomNumber(int max, int min) {
    return rand() % (max + 1 - min) + (min - 1);
  }

}
#endif // MISC_H