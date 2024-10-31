#include "Phonebook.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Phonebook::Phonebook(){
  head = NULL;
}

Phonebook::~Phonebook(){
  cout << "Destroying List: " << endl;
  while(head != NULL){
    cout << "Removing list member: " << head->first_name
	 << " " << head->last_name << " " << head->phone_number << endl;
    delete_user(head->first_name);
  }
}

void Phonebook::push_front(string newFName, string newLName, string newPhone){
  Node *insert = new Node;
  insert -> next = NULL;
  
  insert -> first_name = newFName;
  insert -> last_name = newLName;
  insert -> phone_number = newPhone;

  insert -> next = head;
  head = insert;

}
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

string Phonebook::lookup(string first, string last){
  cout << "Looking up: " << first << " " << last << endl;
  Node *temp;
  
  // Case 1: empty list
  if(head == NULL){
    cout << "Error, Phonebook is empty" << endl;
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
      cout << first << " " << last << " isn't in the phonebook." << endl;
      return "";
    }
    return temp->next->phone_number;
  }
}

string Phonebook::reverse_lookup(string number){
  cout << "Looking for a user with phone number of: " << number << endl;
  Node *temp;
  
  // Case 1: empty list
  if(head == NULL){
    cout << "Error, Phonebook is empty" << endl;
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
      cout << "There isn't a user with the phone number: " << number << " in our system." << endl;
      return "";
    }
    return (temp->next->first_name + " " + temp->next->last_name);
  }
}
	    
void Phonebook::print(){
  Node *printHelper;
  printHelper = head;
  
  while(printHelper != NULL){
    cout << printHelper -> first_name << " "
	 << printHelper->last_name << " " << printHelper->phone_number << endl;
    printHelper = printHelper -> next;
  }
}

void Phonebook::delete_user(string name){
  Node *temp, *eraser;
  
  // Case 1: empty list
  if(head == NULL){
    return;
  }
  // Case 2: Delete the head of the list
  else if (head->first_name == name){
    eraser = head;
    head = head -> next;
    delete eraser; 
  }
  // Case 3: need to search and delete
  else{
    temp = head;

    while(temp->next != NULL && temp->next->first_name != name){
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

