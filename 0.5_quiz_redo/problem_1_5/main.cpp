#include <iostream>
#include <fstream>

using namespace std;

int loadData(int array[], string filename);

void printArray(int array[], int legnth);

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
