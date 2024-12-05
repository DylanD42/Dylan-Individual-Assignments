#include "bst.h"
#include <iostream>
#include <fstream>
#include <cctype> // to lower
using namespace std;

Node::Node(string value){
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

void BST::insert(string value){
  if (root == NULL){
    root = new Node(value);
  }
  else{
    insertHelper(root, value);
  }
}

void BST::insertHelper(Node *current, string value){
  if (value == current->data){
    current->count++;
  }
  else if (value < current->data){
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
  cout << current->data << ":" << current->count << " " << endl;
  printHelper(current->right);
}

void BST::deleteNode(string value){
  deleteHelper(root, value);
}

void BST::deleteHelper(Node *&current, string value){
  // node doesn't exist
  if (current == NULL){
    return;
  }
  // 2 value is < current node's value, go left
  
  if (value < current->data){
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
      current = temp;
    }

    else if (current->right == NULL){
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

void BST::read_file(string filename){
  string word;

  ifstream infile(filename);
  if(!infile){
    cout << "Error, Unable to open the input file." << endl;
    return;
  }
  infile >> word;     ;
  while(infile){
    insert(filter(word));
    infile >> word;  
  }
  infile.close();
}
string BST::filter(string word){
  
  char c;
  string newWord;
  for(int i = 0; i <= static_cast<int>(word.length()); i++){
    c = tolower(word[i]);
    // word[i];
    
    if(
       c >= 97 && c <= 122 
       
       /*
       c != ' ' && c != '!' && c != '?' && c != '.' && c != ',' && c != '&' && c != '$'&&  c != '\'' && c != '\n' &&  c != '\0' &&  c != '*' &&
       c != '"' && c != '%' && c != '(' && c != ')' && c != '-' && c != '_'&&  c != '`'&&  c != '['&&  c != ']' &&  c != ';' &&  c != ':'*/
       ){
      // 
      newWord += c; 
    }
    else{}
  }
  return newWord;
}


void BST::min(){
  minHelper(root);
}
void BST::minHelper(Node *current){
  if(current->left == NULL){
    cout << "MIN: " << current->data << endl;
    return;
  }
  minHelper(current->left);
}

void BST::max(){

}
