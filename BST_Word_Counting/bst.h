#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

class Node {
 public:
  Node(string value);
  Node *left, *right;
  string data;
  int count = 1;
};


class BST {
private:
  Node *root;
  void insertHelper(Node *current, string value);
  void printHelper(Node *current);
  void destructorHelper(Node* current);
  void deleteHelper(Node* &current, string value);
  void minHelper(Node *current);
  void maxHelper(Node *current);
  string filter(string word);
public:
  BST();
  ~BST();
  void insert(string value);
  void set(string word, string value);
  void min();
  void max();
  void print();
  void save_file(string filename);
  void read_file(string filename);
  void deleteNode(string value);
  
};
// bst header file

#endif //BST_H
