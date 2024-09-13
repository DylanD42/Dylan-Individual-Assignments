/**
 * @file main.cpp
 * @author Dylan Daniels
 * @date 2024-09-12
 * @brief uses classes for data of a circle
 * 
 * takes imputs from a user, that of a x,y and radius vaule of a circle
 */


#include <iostream>
#include "circle.h"

using namespace std;

int main() {
  circle myLovelyCircle; // (x,y,radius)
  myLovelyCircle.read();
  myLovelyCircle.print();

  cout << endl << "move(5,7) and resize(25.683) function" << endl;
  // I was unsure what the move and the resize function was for other than changing it manually in the code, because when prompted it automatically assigns the variables in the public class.
  myLovelyCircle.move(5, 7);
  myLovelyCircle.resize(25.683);
  cout << endl;
  myLovelyCircle.print();
  
  return 0;
}
