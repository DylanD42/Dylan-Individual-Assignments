/**
 * @file main.cpp
 * @author Dylan Daniels
 * @date 2024-09-27
 * @brief creation of a custom Vector data type
 * 
 * Program that recreates the behavior of the vector data type, by using dynamic memory 
 * and reallocation as needed, main is a testing ground to prove that all tests are met
 */

#include "Vector.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


/**
 * loads data 
 *
 * @param Vector &v1 is a declared Vector
 * @param string filename is a string with properly formatted file of int's
 * @pre filename must be correct
 * @return void 
 * @post the Vector is properly loaded with the data, reallocates memory as needed
 * 
 */
void loadData(Vector &v1, string filename);

/**
 * prints the loaded vector to the screen
 *
 * @param Vector &v1 is a properly loaded Vector
 * @pre Vector is loaded properly
 * @return void 
 * @post prints out the data within the Vector to the terminal
 * 
 */
void printData(Vector &v1);

int main() {
  Vector v1,set1,set2; // v1 will hold 1000+ integers, set1 and 2 will hold 10 numbers
                      // set 1 and set 2 will be used to demonstrate "=" operator later

  loadData(v1,"numbers.txt");
  loadData(set1, "10nums_1.txt");
  loadData(set2, "10nums_2.txt");

  cout << "Test case #1 & #2 & #3: Loading 1000+ integers using push_back(), Use of [] operator, and using size() for loop bounds " << endl;
  printData(v1);


  
  cout << "Test case #4 = operator" << endl;
  cout << "( Pre assignment ) Set 1: " << endl; printData(set1);
  cout << "( Pre assignment ) Set 2: " << endl; printData(set2);
  cout << " set1 = set2 "<< endl;
  
  set1 = set2; // when assignment takes place it prints the addresses of both arrays
              //  to prove that it is a deep copy. Also below I did individual reassignments
             //   to further prove how they are independent!
  
  cout << "( Post assignment ) Set 1: " << endl; printData(set1);
  cout << "( Post assignment ) Set 2: " << endl; printData(set2);
  
  set1[0] = 10000;
  set2[5] = 5678643;
  
  cout << "( index 0 to 10000 ) Set 1: " << endl; printData(set1);
  cout << "( index 5 to 5678643 ) Set 2: " << endl; printData(set2);

  cout << "Test case #5: copy constructor" << endl;
  
  Vector v2(set2); // Makes v2 be a deep copy of set2.

  cout << "v2: " << endl; printData(v2);
  return 0;
} 
void loadData(Vector &v1, string filename){
  
  ifstream infile; 
  infile.open(filename);
  int number;
  infile >> number;
  while(infile){
    v1.push_back(number); // loads the number read in by infile to the end of the Vector,
                         //  it calls the reserve() function as more memory is needed
    infile >> number;
  }
 
  infile.close();
}

void printData(Vector &v1){
  for(int i = 0; i < v1.size(); i++){
    
    cout << "position " << i << ": " << v1[i] << endl;
    
  }
  
  cout << endl;
}
