#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>

using namespace std;

struct Node{
  Node *next;
  
  string first_name;
  string last_name;
  string phonenumber;
};


class Phonebook{
 private:
  Node *head;
 public:
  Phonebook();
  ~Phonebook();
  void push_front();
  void push_back();
  void read_from_file(string filename);
  void write_to_file(string filename);
  void insert_sorted();
  string lookup(string name);
  string reverse_lookup(string number);
  void print();
  void delete_user(string name);

};

#endif //PHONEBOOK_H
