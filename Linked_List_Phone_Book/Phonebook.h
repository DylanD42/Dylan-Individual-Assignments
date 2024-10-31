/**
 * @file Phonebook.cpp
 * @author Dylan Daniels
 * @date 2024-10-30
 * @brief header file for a linked list phonebook
 * 
 * Uses a linked list ADT to make a phonebook where you can add / remove users and lookup users by phone number or name.
 */
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>

using namespace std;


/**
 * node struct for linked list
 *
 * @struct Node{ Phonebook.h "Linked_List_Phone_Book/Phonebook.h"
 * @brief holds data for each node in the linked list
 *
 */
struct Node{
  Node *next;
  
  string first_name;
  string last_name;
  string phone_number;
};



/**
 * phonebook class w/ linked list ADT
 *
 * @class Phonebook{ Phonebook.h "Linked_List_Phone_Book/Phonebook.h"
 * @brief is the class for the phonebook that works with node struct to create a linked list of users
 *
 */
class Phonebook{
 private:
  Node *head;
 public:
  /**
 * constructor for phonebook class
 *
 * @pre 
 * @post sets the head of the pb to null
 * 
 */
  Phonebook();
  /**
 * destructor for the phonebook class
 *
 * @pre phonebook is properly created
 * @post deallocates memory taken up by the nodes
 * 
 */
  ~Phonebook();
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
  void push_front(string newFName, string newLName, string newPhone);
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
  void push_back(string newFName, string newLName, string newPhone);
  /**
 * reads in data from file
 *
 * @param string filename is a valid filename to be opened
 * @pre phonebook is created and filename is correct
 * @return void 
 * @post loads the data from the properly formatted file into the linked list in the order read in from file
 * 
 */
  void read_from_file(string filename);
  /**
 * writes to file
 *
 * @param string filename is a proper file to write to
 * @pre phonebook is created and preferably loaded with data
 * @return void 
 * @post data is written to file
 * 
 */
  void write_to_file(string filename);
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
  void insert_sorted(string first, string last, string number);
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
  string lookup(string first, string last);
  /**
 * looks up users name from phone number
 *
 * @param string number is a properly loaded phonenubmer
 * @pre phonebook is loaded with data
 * @return string the first and last name concatnated with spaces to displace the full name
 * @post 
 * 
 */
  string reverse_lookup(string number);
  /**
 * prints the data
 *
 * @pre phonebook is created and preferably loaded with data
 * @return void 
 * @post the phonebook is printed
 * 
 */
  void print();
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
  void delete_user(string first, string last);

};

#endif //PHONEBOOK_H
