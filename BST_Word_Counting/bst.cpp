#include "bst.h"
#include <iostream>
#include <fstream>
#include <cctype> // to lower


Node::Node(string value){
  left = NULL;
  right = NULL;
  data = value;
  count = 1;
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
  string newValue = filter(value);
  if (root == NULL){
    root = new Node(newValue);
  }
  else{
    insertHelper(root, newValue);
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
void BST::writeFile(string filename){
  ofstream ofile(filename);
  if(!ofile){
   cout << "File could not be opened." << endl;
   return;
  }
  writeHelper(ofile, root);
  cout << "Successfully wrote data to: " << filename << endl;
}
void BST::writeHelper(ofstream& ofile,Node *current){
  if (current == NULL){
      return;
  }
  writeHelper(ofile, current->left);
  ofile << current->data << ":" << current->count << " " << endl;
  writeHelper(ofile, current->right);
}
void BST::deleteNode(string value){
  string newValue = filter(value);
  deleteHelper(root, newValue);
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

void BST::readFile(string filename){
  string word, filteredWord;

  ifstream infile(filename);
  if(!infile){
    cout << "Error, Unable to open the input file." << endl;
    return;
  }
  infile >> word;
  while(infile){
    word = filter(word);
    if(!word.empty()){
      insert(word);
    }
    infile >> word;  
  }
  cout << "Successfully read data from: " << filename << endl;
  infile.close();
}
string BST::filter(string word){
  
  char c;
  string newWord;
  for(int i = 0; i < static_cast<int>(word.length()); i++){
    c = tolower(word[i]);
    if(c >= 97 && c <= 122){
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
    cout << "The smallest value in the BST is \"" << current->data << "\" and it appears "
	 << current->count << " times." << endl;
    return;
  }
  minHelper(current->left);
}

void BST::max(){
  maxHelper(root);
}

void BST::maxHelper(Node *current){
  if(current->right == NULL){
     cout << "The largest value in the BST is \"" << current->data << "\" and it appears "
         << current->count << " times." << endl;
    return;
  }
  maxHelper(current->right);
}

void BST::find(string word){
  string newWord = filter(word);
  bool found = false;
  findHelper(root, newWord, found);
  if (!found) {
    cout << newWord << " wasn't found in the BST." << endl;
  }
}

void BST::findHelper(Node *current, string word, bool &found){
  if (current == NULL) {
        return;
    }

    if (current->data == word) {
        cout << word << " was found " << current->count << " times." << endl;
        found = true;
        return;
    }

    findHelper(current->left, word, found);
    findHelper(current->right, word, found);  
}

/*
void BST::set(string word, int setCount){
  deleteNode(word);
  for(int i = 0; i < setCount; i++){
    insert(word);
  }
}*/
//void BST::setHelper(string word, int setCount, Node *current)
void BST::set(string word, int setCount){
  //deleteNode(word);
  setHelper(root,filter(word),setCount);
}

void BST::setHelper(Node *current, string word, int setCount){
  if (word == current->data){
    current->count = setCount;
  }
  else if (current == NULL){
    insert(word);
    setHelper(root, word,setCount);
  }
  else if (word < current->data){
    if (current->left == NULL) {
      current->left = new Node(word);
      current->left->count = setCount;
    }
    else{
      setHelper(current->left, word, setCount);
    }
  }
  else {
    if ((*current).right == NULL){
      (*current).right = new Node(word);
      current->right->count = setCount;
    }
    else{
      setHelper((*current).right, word, setCount);
    }
  }
}


