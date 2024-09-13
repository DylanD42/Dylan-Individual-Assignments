/**
 * @file main.cpp
 * @author Dylan Daniels
 * @date 2024-09-12
 * @brief Dynamic array program
 * 
 * uses dynamic arrays, loads in a specific ammount of data from a file, with the array being tuned to the ammount of data loaded, then printed
 */

#include <iostream>
#include <fstream>

using namespace std;


/**
 * loads in data from file2.txt into the dynamic array
 *
 * @param int array[] is a dynamic array with the size of how many elements to be read in
 * @param int size is the ammount of elements to be read in/ also is the size of the array
 * @pre the dynamic array is propery created and size is a integer imputed from the user
 * @return void 
 * @post array is loaded with proper data
 * 
 */
void load_array(int array[], int size);

/**
 * prints the array
 *
 * @param int array[] is a properly loaded dynamic array with data from file2.txt
 * @param int size is the size of the array and number of elements in the array
 * @pre array and size are properly set
 * @return void 
 * @post prints the array
 * 
 */
void print_array(int array[], int size);
ifstream infile;

int main() {
  int *array;
  int size;

  cout << "size of the array: ";
  cin >> size;

  array = new int[size];
  load_array(array, size);
  print_array(array,size);
  return 0;
}

void load_array(int array[], int size){
  infile.open("file2.txt");
  cout << endl;
  for(int i = 0; i < size; i++){
    infile >> array[i];
  }
  
}


void print_array(int array[], int size){
  for(int i = 0; i < size; i++){
    cout << i+1 << ": " <<array[i] << endl;
   }
}
