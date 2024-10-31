#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>

using namespace std;

struct Node{
  Node *next;
  
  string first_name;
  string last_name;
  string phone_number;
};


class Phonebook{
 private:
  Node *head;
 public:
  Phonebook();
  ~Phonebook();
  void push_front(string newFName, string newLName, string newPhone);
  void push_back(string newFName, string newLName, string newPhone);
  void read_from_file(string filename);
  void write_to_file(string filename);
  void insert_sorted(string first, string last, string number);
  string lookup(string first, string last);
  string reverse_lookup(string number);
  void print();
  void delete_user(string first, string last);

};

#endif //PHONEBOOK_H
