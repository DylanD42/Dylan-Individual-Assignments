
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
    cout << "Removing list member: " << head ->data << endl;
    delete_user(head->data);
  }
}

void Phonebook::push_front(string newData){
  Node *insert = new Node;
  insert -> next = NULL;
  insert -> data = newData;

  insert -> next = head;
  head = insert;

}

void Phonebook::push_back(string newData){
  Node *newNode = new Node;
  newNode -> next = NULL;
  newNode -> data = newData;

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

void Phonebook::read_from_file(string filename){}

void Phonebook::write_to_file(string filename){}

void Phonebook::insert_sorted(){}

string Phonebook::lookup(string name){}

string Phonebook::reverse_lookup(string number){}

void Phonebook::print(){
  Node *printHelper;

  cout << "HEAD -->";
  //start at the head
  printHelper = head;
  
  while(printHelper != NULL){
    cout << printHelper -> data << "-->";
    printHelper = printHelper -> next;
  }
  cout << "NULL" << endl;
}

void Phonebook::delete_user(string name){
  Node *temp, *eraser;
  
  // Case 1: empty list
  if(head == NULL){
    return;
  }
  // Case 2: Delete the head of the list
  else if (head->data == name){
    eraser = head;
    head = head -> next;
    delete eraser; 
  }
  // Case 3: need to search and delete
  else{
    temp = head;

    while(temp->next != NULL && temp->next->data != name){
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

