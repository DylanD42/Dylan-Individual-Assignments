#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

class Node {
 public:
  Node(int value);
  Node *left, *right;
  int data;
};


class BST {
private:
  Node *root;
  void insertHelper(Node *current, int value);
  void printHelper(Node *current);
  void destructorHelper(Node* current);
  void deleteHelper(Node* &current, int value);
public:
  BST();
  ~BST();
  void insert(int value);
  void set(string word, int value);
  void min();
  void max();
  void print();
  void save_file(string filename);
  void deleteNode(int value);
  
};
// bst header file

#endif //BST_H
