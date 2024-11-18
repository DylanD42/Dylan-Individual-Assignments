#ifndef BST_H
#define BST_H

#include <iostream>

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
public:
  BST();
  ~BST();
  void insert(int value);
  void print();
  void deleteNode(int value);
  void deleteHelper(Node* &current, int value);
};
// bst header file

#endif //BST_H
