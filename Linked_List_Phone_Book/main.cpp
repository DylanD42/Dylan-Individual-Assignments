#include "Phonebook.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  Phonebook pb;
  string defaultInfile = "phonebook.txt";
  string defaultOutfile = "phonebookOut.txt";
  string userInfile, userOutfile;
  int userImput = 0;
  int secondImput = 0;
  cout << "Welcome to the UTM Phonebook!, You may select one of the following options:" << endl;
  while(userImput != 8){
    cout << "1 Read a phonebook from a file" << endl
	 << "2 Write the phonebook to a file" << endl
	 << "3 Print the phonebook" << endl
	 << "4 Search for a user's phone number" << endl
	 << "5 Reverse lookup by phone number" << endl
	 << "6 Add a user" << endl
	 << "7 Delete a user" << endl
	 << "8 Exit this program" << endl
	 << "Please enter your choice now: ";
    cin >> userImput;
    cout << endl << endl;
    
    if(userImput == 1){
      cout << "Do you want to choose a file (1) or a predetermined one(2): ";
      cin >> secondImput;
      if(secondImput == 1){
	cin >> userInfile;
	pb.read_from_file(userInfile);
	
      }
      else if(secondImput == 2){
	pb.read_from_file(defaultInfile);

      }
    }
    
  }
  
  
  
  pb.read_from_file(file);
  pb.write_to_file("phonebookOut.txt");
  pb.print();
  return 0;
}

//void option1(){}
