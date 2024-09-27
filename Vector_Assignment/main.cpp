#include "Vector.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//void loadData(Vector &v1, string filename);
void printData(Vector &v1);
int main() {
  
  Vector newVector;
  Vector newVector2;
  //Vector newVector3;

  //cout << "pre load vector 1; size:" << newVector.size() << " Capacticy: " << newVector.capacity() << endl;
  //cout << "pre load vector 2; size:" << newVector2.size() << " Capacticy: " << newVector2.capacity() << endl;
  
  //loadData(newVector2, "numbers.txt");
  //loadData(newVector,"num.txt");
  
  //cout << "vector 1; size:" << newVector.size() << " Capacticy: " << newVector.capacity() << endl;
  //cout << "vector 2; size:" << newVector2.size() << " Capacticy: " << newVector2.capacity() << endl;
  //loadData(newVector3, "text.txt");
  
  //printData(newVector);
  //cout << endl;
  //printData(newVector2);
  //cout << endl;
  //printData(newVector3);
  //cout << newVector[0];
  return 0;
}
void loadData(Vector &v1, string filename){
  
  ifstream infile; 
  infile.open(filename);
  int number;
  
  infile >> number;
  //cout << number << endl;
  while(infile){
    v1.push_back(number);
    infile >> number;
  }
 
  infile.close();
}

void printData(Vector &v1){
  for(int i = 0; i < v1.size(); i++){
    
    cout << "position " << i << ": " << v1[i] << endl;
    
  }
  
  
}
