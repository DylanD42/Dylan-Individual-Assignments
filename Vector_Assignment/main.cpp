#include "Vector.h"
#include <iostream>
#include <fstream>

using namespace std;

void loadData(Vector v1);

int main() {
  
  Vector newVector;

  newVector.reserve(2);
  newVector.reserve(10);
  //newVector.reserve(100);
  cout << "before pushback" << endl;
  newVector.push_back(5);
  cout << "after pushback" << endl;
  int test = newVector.capacity();
  //int test2 = newVector.size();
  cout << test << " "
    //<< test2
       << endl;
  
  //newVector[0] = 1;
  //int test = newVector[0];
  //int size = newVector.size();
  //cout << size;
  //cout << test << endl;
  //newVector.capacity();

  
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
