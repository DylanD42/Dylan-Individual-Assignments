#include "Vector.h"
#include <iostream>
#include <fstream>

using namespace std;

void loadData(Vector v1);

int main() {
  
  Vector newVector;

  newVector.reserve(10);
  newVector[0] = 1;
  int test = newVector[0];
  int size = newVector.size();
  cout << size;
  //cout << test << endl;
  //loadData(newVector);
  return 0;
}

void loadData(Vector v1){
  
  ifstream infile; 
  infile.open("numbers.txt");
  int number;
  
  infile >> number;
  while(infile){
    v1.push_back(number);
    infile >> number;
  }
  
  infile.close();
}
