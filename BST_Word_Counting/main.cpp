//main file

#include <iostream>
#include "bst.h"
using namespace std;

int main() {
  BST tree;
  tree.print();
  tree.insert(6);
  tree.print();
  tree.insert(3);
  tree.print();
  tree.insert(7);
  tree.print();
  tree.insert(5);
  tree.print();
  tree.insert(9);
  tree.print();
  tree.insert(1);
  tree.print();
  tree.insert(2);

  cout << "Final tree:\n";
  tree.print();

  tree.deleteNode(1);
  cout << "Tree after delete:\n";
  tree.print();
  
  return 0;
}
