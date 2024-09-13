/**
 * @file circle.cpp
 * @author Dylan Daniels
 * @date 2024-09-12
 * @brief class that stores data for a circles pos and radius
 * 
 * class that stores data for a circles pos and radius from the user
 */

#include "circle.h"
#include <iostream>

using namespace std;

void circle::resize(float new_radius){
  radius = new_radius;
}



void circle::move(int new_x, int new_y){
  x = new_x;
  y = new_y;
  
}

void circle::print(){

  cout << "x: " << x << " y: " << y << " radius: " << radius << endl; 

}

void circle::read(){

  cout << " x?: ";
  cin >> x;
  cout << " y?: ";
  cin >> y;
  cout << " radius?: ";
  cin >> radius;

}
