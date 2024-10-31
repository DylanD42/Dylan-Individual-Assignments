/**
 * @file Phonebook.cpp
 * @author Dylan Daniels
 * @date 2024-10-30
 * @brief code for a linked list phonebook
 * 
 * Uses a linked list ADT to make a phonebook where you can add / remove users and lookup users by phone number or name.
 */

#include "Phonebook.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


/**
 * constructor for phonebook class
 *
 * @pre 
 * @post sets the head of the pb to null
 * 
 */
Phonebook::Phonebook(){
  head = NULL;
}


/**
 * destructor for the phonebook class
 *
 * @pre phonebook is properly created
 * @post deallocates memory taken up by the nodes
 * 
 */
Phonebook::~Phonebook(){
  cout << "Destroying List: " << endl;
  while(head != NULL){
    cout << "Removing list member: " << head->first_name
	 << " " << head->last_name << " " << head->phone_number << endl;
    delete_user(head->first_name, head->last_name);
  }
}


/**
 * loads in the first node at the front
 *
 * @param string newFName properly loaded first name
 * @param string newLName properly loaded last name
 * @param string newPhone properly loaded phone number
 * @pre phonebook is created
 * @return void 
 * @post the loaded data is put into the first positon of the linked list pushing everything else back
 * 
 */
void Phonebook::push_front(string newFName, string newLName, string newPhone){
  Node *insert = new Node;
  insert -> next = NULL;
  
  insert -> first_name = newFName;
  insert -> last_name = newLName;
  insert -> phone_number = newPhone;

  insert -> next = head;
  head = insert;

}

/**
 * loads in data to the tail
 *
 * @param string newFName properly loaded first name
 * @param string newLName properly loaded last name
 * @param string newPhone properly loaded phone number
 * @pre phonebook is created
 * @return void 
 * @post pushes back the data to make the new data the last element of the linked list
 * 
 */
void Phonebook::push_back(string newFName, string newLName, string newPhone){
  Node *newNode = new Node;
  newNode -> next = NULL;
  
  newNode -> first_name = newFName;
  newNode -> last_name = newLName;
  newNode -> phone_number = newPhone;

  // case 1: list is empty
  if (head == NULL){
    head = newNode;
  }
  // Case 2: List is not empty
  else{
    Node *end = head;
    while (end -> next != NULL){
      end =  end -> next;      
    }
    end -> next = newNode;
  }
}


/**
 * reads in data from file
 *
 * @param string filename is a valid filename to be opened
 * @pre phonebook is created and filename is correct
 * @return void 
 * @post loads the data from the properly formatted file into the linked list in the order read in from file
 * 
 */
void Phonebook::read_from_file(string filename){
  string TempFirst, TempLast, TempNumber;
  ifstream infile(filename);
  if(!infile){
    cout << "Error. Unable to open the input file." << endl;
  }
  infile >> TempFirst >> TempLast >> TempNumber;
  while(infile){
    push_back(TempFirst, TempLast, TempNumber);
    infile >> TempFirst >> TempLast >> TempNumber;
  }
  infile.close();
}


/**
 * writes to file
 *
 * @param string filename is a proper file to write to
 * @pre phonebook is created and preferably loaded with data
 * @return void 
 * @post data is written to file
 * 
 */
void Phonebook::write_to_file(string filename){
  ofstream outfile(filename);
  if (!outfile){
    cout << "Error. Unable to open the output file." << endl;
  }
  
  Node *writeHelper;
  //start at the head
  writeHelper = head;
  
  while(writeHelper != NULL){
    outfile << writeHelper -> first_name << " "
	 << writeHelper->last_name << " " << writeHelper->phone_number << endl;
    writeHelper = writeHelper -> next;
  }
  outfile.close();
}


/**
 * puts a new node in the middle of the linked list according to where it belongs alphabetically 
 *
 * @param string first loaded first name
 * @param string last loaded last name
 * @param string number loaded phone number
 * @pre phonebook is created and data is loaded 
 * @return void 
 * @post inserts the data into proper location sorting by last name alphabetically 
 * 
 */
void Phonebook::insert_sorted(string first, string last, string number){
  Node *before, *after;
  Node *current = new Node;
  //Case 1 Inserted belongs at head
  if(last < head->last_name){
    push_front(first, last, number);
    return;
  }
  //Case 2 Inserted belongs somewhere in middle
  if(last != head->last_name){
    after = head->next;
    before = head;
    while(after != NULL && !(last < after->last_name)){
      before = before->next;
      after = after->next;
    }
    if(before->next == NULL){
      push_back(first, last, number);
      return;
    }
    if(last < after->last_name){
      current->first_name = first;
      
      current->last_name = last;
      current->phone_number = number;
      current->next = after;
      
      before->next = current;
      return;
    }
  }
  return;
}


/**
 * looks up user by name
 *
 * @param string first properly loaded first name
 * @param string last properly loaded last name 
 * @pre phonebook is loaded with data
 * @return string the phonenumber associated with that name
 * @post 
 * 
 */
string Phonebook::lookup(string first, string last){
  
  Node *temp;
  
  // Case 1: empty list
  if(head == NULL){
    cout << endl << "Error, Phonebook is empty" << endl;
    return "";
  }
  // Case 2: head of list is the lookup name
  else if (head->first_name == first && head->last_name == last){
    return head->phone_number;
  }
  // Case 3: need to search and delete
  else{
    temp = head;

    while(temp->next != NULL && temp->next->first_name != first && temp->next->last_name != last){
      temp = temp->next;
  }
    // if no such value
    if(temp -> next == NULL){
      cout << endl << first << " " << last << " isn't in the phonebook." << endl;
      return "";
    }
    return temp->next->phone_number;
  }
}


/**
 * looks up users name from phone number
 *
 * @param string number is a properly loaded phonenubmer
 * @pre phonebook is loaded with data
 * @return string the first and last name concatnated with spaces to displace the full name
 * @post 
 * 
 */
string Phonebook::reverse_lookup(string number){
  
  Node *temp;
  
  // Case 1: empty list
  if(head == NULL){
    cout << endl << "Error, Phonebook is empty" << endl;
    return "";
  }
  // Case 2: head of list is the lookup name
  else if (head->phone_number == number){
    return (head->first_name + " " + head->last_name);
  }
  // Case 3: need to search and delete
  else{
    temp = head;
    while(temp->next != NULL && temp->next->phone_number != number){
      temp = temp->next;
    }
    // if no such value
    if(temp -> next == NULL){
      cout << endl << "There isn't a user with the phone number: " << number << " in our system." << endl;
      return "";
    }
    return (temp->next->first_name + " " + temp->next->last_name);
  }
}
	    

/**
 * prints the data
 *
 * @pre phonebook is created and preferably loaded with data
 * @return void 
 * @post the phonebook is printed
 * 
 */
void Phonebook::print(){
  Node *printHelper;
  printHelper = head;
  cout << endl << endl;
  while(printHelper != NULL){
    cout << printHelper -> first_name << " "
	 << printHelper->last_name << " " << printHelper->phone_number << endl;
    printHelper = printHelper -> next;
  }
  cout << endl << endl;
}


/**
 * deletes user
 *
 * @param string first proper first name
 * @param string last proper last name
 * @pre phonebook is created and is preferablly loaded with data
 * @return void 
 * @post the user proved is deleted from the linked list
 * 
 */
void Phonebook::delete_user(string first, string last){
  Node *temp, *eraser;
  
  // Case 1: empty list
  if(head == NULL){
    return;
  }
  // Case 2: Delete the head of the list
  else if ((head->first_name == first)&&(head->last_name == last)){
    eraser = head;
    head = head -> next;
    delete eraser; 
  }
  // Case 3: need to search and delete
  else{
    temp = head;

    while((temp->next != NULL && temp->next->first_name != first)
	  && (temp->next != NULL && temp->next->last_name != last)){
      temp = temp->next;
    }
    // if no such value
    if(temp -> next == NULL){
      return;
    }
    eraser = temp->next;
    temp->next = eraser->next;
    delete eraser;
    
  }
  
}

