//main file

#include <iostream>
#include "bst.h"
using namespace std;

int main() {
  BST tree;/*
  tree.print();
  tree.insert("F");
  tree.print();
  tree.insert("C");
  tree.print();
  tree.insert("G");
  tree.print();
  tree.insert("E");
  tree.print();
  tree.insert("H");
  tree.print();
  tree.insert("A");
  tree.print();
  tree.insert("B");
  tree.insert("H");

  cout << "Final tree:\n";
  tree.print();

  
  tree.deleteNode("E");
  cout << "Tree after delete:\n";
  tree.print();
	   */
  tree.read_file("sherlock.txt");
  tree.print();
  return 0;
}
