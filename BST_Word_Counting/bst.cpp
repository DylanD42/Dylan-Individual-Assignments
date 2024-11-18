#include "bst.h"
#include <iostream>

using namespace std;

Node::Node(int value){
  left = NULL;
  right = NULL;
  data = value;
}

BST::BST() {
  root = NULL;
}

BST::~BST() {
  destructorHelper(root);
}

void BST::destructorHelper(Node *current){
  if (current == NULL){
    return;
  }
  destructorHelper(current->left);
  destructorHelper(current->right);
  delete current;
}

void BST::insert(int value){
  if (root == NULL){
    root = new Node(value);
  }
  else{
    insertHelper(root, value);
  }
}

void BST::insertHelper(Node *current, int value){
  if (value < current->data){
    if (current->left == NULL) {
      current->left = new Node(value);
    }
    else{
      insertHelper(current->left, value);
    }
  }
  else {
    if ((*current).right == NULL){
      (*current).right = new Node(value);
    }
    else{
      insertHelper((*current).right, value);
    }
  }
}

void BST::print(){
  printHelper(root);
  cout << endl;
}

void BST::printHelper(Node *current){
  if (current == NULL){
    return;
  }
  printHelper(current->left);
  cout << current->data << " ";
  printHelper(current->right);
}

void BST::deleteNode(int value){
  deleteHelper(root, value);
}

void BST::deleteHelper(Node *&current, int value){
  // node doesn't exist
  if (current == NULL){
    return;
  }
  // 2 value is < current node's value, go left
  else if (value < current->data){
    deleteHelper(current->left, value);
  }

  // 3 value is > current node's value, go right
  else if (value > current->data){
    deleteHelper(current->right, value);
  }
  //4 found it
  else {
    // 4.1 leaf node
    Node *temp;

    if (current->left == NULL){
      temp = current->right;
      delete current;
      current == temp;
    }

    if (current->right == NULL){
      temp = current->left;
      delete current;
      current = temp;
    }

    else{
      temp = current->right;
      Node *parent = NULL;

      while(temp->left != NULL){
	parent = temp;
	temp = temp->left;
      }
      current->data = temp->data;

      if (parent != NULL){
	deleteHelper(parent->left, parent->left->data);
      }
      else{
	deleteHelper(current->right, current->right->data);
      }
    }
    // 4.2 no left subtree
    
  }
}
