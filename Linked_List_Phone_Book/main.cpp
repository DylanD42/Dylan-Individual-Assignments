#include "Phonebook.h"
#include <iostream>
#include <string>
using namespace std;


int main() {
  Phonebook pb;
  string defaultInfile = "phonebook.txt";
  string defaultOutfile = "phonebookOut.txt";
  string userInfile, userOutfile, first, last, phone;
  int userImput = 0;
  int secondImput = 0;
  cout << "Welcome to the UTM Phonebook!, You may select one of the following options:" << endl;
  while(userImput != 8){
    
    cout << endl
	 << "1 Read a phonebook from a file" << endl
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
      secondImput = 0;
      cout << "Select a file to read in." << endl;
      cout << "Do you want to choose a file (1) or a predetermined one(2): ";
      cin >> secondImput;
      if(secondImput == 1){
	cin >> userInfile;
	pb.read_from_file(userInfile);
      }
      else if(secondImput == 2){
	pb.read_from_file(defaultInfile);
      }
      else{
	cout << "Unable to open file, reselect option 1 to retry." << endl;
      }
    }
    else if(userImput == 2){
	secondImput = 0;
	cout << "Select a file to write to." << endl;
	cout << "Do you want to choose a file (1) or a predetermined one(2): ";
	cin >> secondImput;
	if(secondImput == 1){
	  cin >> userOutfile;
	  pb.write_to_file(userOutfile);
	}
	else if(secondImput == 2){
	  pb.write_to_file(defaultOutfile);
	}
	else{
	  cout << "Unable to open file, reselect option 2 to retry." << endl;
	}
	
      }
    else if(userImput == 3){
      pb.print();
    }
    else if(userImput == 4){
      cout << "Enter the first name of whose number you would like to lookup: ";
      cin >> first;
      cout << "Enter the last name of whose number you would like to lookup: ";
      cin >> last;
      cout << endl << "The phone number associated with " << first << " " << last << " is: "
	   << pb.lookup(first,last) << endl;
    }
    else if(userImput == 5){
      cout << "Enter the phone number of whose name you would like to lookup:";
      cin >> phone;
      cout << endl <<"The person associated with the phone number: " << phone << " is: "
	   << pb.reverse_lookup(phone) << endl;
    }
    else if(userImput == 6){
      cout << "To add a user please enter first name: ";
      cin >> first;
      cout << "To add a user please enter last name: ";
      cin >> last;
      cout << "To add a user please enter phone number: ";
      cin >> phone;
      pb.insert_sorted(first, last, phone);
    }
    else if(userImput == 7){
      cout << "To delete user please enter first name: ";
      cin >> first;
      cout << "To delete a user please enter last name: ";
      cin >> last;
      pb.delete_user(first, last);
    }
  }
  return 0;
}
