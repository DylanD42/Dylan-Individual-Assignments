#include "Vector.h"
#include <iostream>
#include <fstream>

using namespace std;

void loadData(Vector v1);

int main() {
  ifstream infile;
  Vector newVector;
  //newVector.reserve(1);

  infile.open("numbers.txt");
  int number;
  infile >> number;
  cout << number << endl;
  while(infile){
    newVector.push_back(number);
    infile >> number;
  }
  
  
  //loadData(newVector);
  return 0;
}
/*
void loadData(Vector v1){
  
  ifstream infile; 
  infile.open("num.txt");
  int number;
  
  infile >> number;
  while(!infile){
    v1.push_back(number);
    infile >> number;
  }
 
  infile.close();
}
*/
