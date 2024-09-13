/**
 * @file main.cpp
 * @author Dylan Daniels
 * @date 2024-09-12
 * @brief Loads data and prints array and average
 * 
 * Loads a file containing a list of ints into a static array and the prints out the loaded array and the average of the ints
 */

#include <iostream>
#include <fstream>

using namespace std;




/**
 * Reads in a file and loads the data into a static array and returns the number of elements in the file
 *
 * @param int array[] is a empty static array for the list of ints
 * @param string filename is a predeterimed filename, the name of the file containing the integers
 * @pre the array is properly initialized
 * @return int return the number of elements in the file
 * @post 
 * 
 */
int loadData(int array[], string filename);


/**
 * prints the array
 *
 * @param int array[] is a array with the loaded data from the file
 * @param int legnth is the proper length of the elements in the array
 * @pre array is loaded properly, and legnth is correct.
 * @return void 
 * @post prints the array to the screen
 * 
 */
void printArray(int array[], int legnth);


/**
 * prints the average of all the numbers in the array
 *
 * @param int array[] is a array with the loaded data from the file
 * @param int legnth is the proper length of the elements in the array
 * @pre array and length are loaded correctly
 * @return float returns the average of the elements as a float
 * @post
 * 
 */
float calcAvg(int array[], int legnth);


int MAX_ARRAY = 1000;
ifstream infile;

int main() {
 
  int array[MAX_ARRAY];
  int total = loadData(array, "file.txt");

  printArray(array, total);
  float average = calcAvg(array, total);
  cout << "Average: " << average << endl;
  return 0;
}

int loadData(int array[], string filename){

   infile.open(filename);
   int n = 0;
   infile >> array[n];
   while(infile){
     n++;
     infile >> array[n];
   };
   infile.close();
   return n-1;
}

void printArray(int array[], int legnth){
    for(int i = 0; i <= legnth; i++){
      cout << i+1 << ": " <<array[i] << endl;
    }
}

float calcAvg(int array[], int legnth){
  float avg = 0;
  for(int i = 0; i <= legnth; i++){
    avg += array[i];

  }
  return(avg/legnth);

}
