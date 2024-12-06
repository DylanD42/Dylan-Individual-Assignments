#include "bst.h"
#include <iostream>
#include <fstream>
#include <cctype> // to lower

/**
* Constructor for the Node class
* 
* @param value The value to initialize the node with
* @pre None
* @post The node is created with the given value, left and right children are set to null, and the count is set to 1.
*/
Node::Node(string value){
  left = NULL;
  right = NULL;
  data = value;
  count = 1;
}

/**
 * Constructor for the BST class
 * 
 * @pre None
 * @post The BST is created with the root set to NULL.
 */
BST::BST() {
  root = NULL;
}

/**
 * Destructor for the BST class
 * 
 * @pre The BST is properly created
 * @post All dynamically allocated memory is deallocated using the destructor helper function.
 */
BST::~BST() {
  destructorHelper(root);
}

/**
 * Recursive helper function to delete nodes in the BST
 * 
 * @param current Pointer to the current node being processed
 * @pre The BST is created
 * @post The nodes are deleted in post-order (left, right, current)
 */
void BST::destructorHelper(Node *current){
  if (current == NULL){
    return;
  }
  destructorHelper(current->left);
  destructorHelper(current->right);
  delete current;
}

/**
 * Inserts a value into the BST
 * 
 * @param value The value to insert into the BST
 * @pre The BST is created
 * @post The value is inserted in the correct position according to BST rules
 */
void BST::insert(string value){
  string newValue = filter(value);
  if (root == NULL){
    root = new Node(newValue);
  }
  else{
    insertHelper(root, newValue);
  }
}

/**
 * Recursive helper function to insert a value into the BST
 * 
 * @param current The current node being examined
 * @param value The value to insert
 * @pre The BST is created
 * @post The value is inserted in the correct position according to BST rules
 */
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

/**
 * Prints the BST in-order (left, current, right)
 * 
 * @pre The BST is created
 * @post The BST is printed to the console
 */
void BST::print(){
  printHelper(root);
  cout << endl;
}

/**
 * Recursive helper function to print the BST
 * 
 * @param current The current node being printed
 * @pre The BST is created
 * @post The BST is printed to the console
 */
void BST::printHelper(Node *current){
  if (current == NULL){
    return;
  }
  printHelper(current->left);
  cout << current->data << ":" << current->count << " " << endl;
  printHelper(current->right);
}


/**
 * Writes the BST to a file
 * 
 * @param filename The name of the file to write to
 * @pre The BST is created
 * @post The BST is written to the specified file
 */
void BST::writeFile(string filename){
  ofstream ofile(filename);
  if(!ofile){
   cout << "File could not be opened." << endl;
   return;
  }
  writeHelper(ofile, root);
  cout << "Successfully wrote data to: " << filename << endl;
}

/**
 * Recursive helper function to write the BST to a file
 * 
 * @param ofile The output file stream
 * @param current The current node being written
 * @pre The BST is created
 * @post The BST is written to the specified file
 */
void BST::writeHelper(ofstream& ofile,Node *current){
  if (current == NULL){
      return;
  }
  writeHelper(ofile, current->left);
  ofile << current->data << ":" << current->count << " " << endl;
  writeHelper(ofile, current->right);
}

/**
 * Deletes a node from the BST
 * 
 * @param value The value to delete from the BST
 * @pre The BST is created
 * @post The node containing the value is removed from the BST
 */
void BST::deleteNode(string value){
  string newValue = filter(value);
  deleteHelper(root, newValue);
}


/**
 * Recursive helper function to delete a node from the BST
 * 
 * @param current A reference to the current node being examined
 * @param value The value to delete
 * @pre The BST is created
 * @post The node containing the value is removed from the BST
 */
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

/**
 * Reads data from a file and inserts it into the BST
 * 
 * @param filename The name of the file to read from
 * @pre The BST is created
 * @post Data from the file is inserted into the BST
 */
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

/**
 * Filters a word to only contain alphabetic characters in lowercase
 * 
 * @param word The word to filter
 * @return The filtered word
 * @pre The word is a string
 * @post Returns a string with only lowercase alphabetic characters
 */
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

/**
 * Finds the minimum value in the BST
 * 
 * @pre The BST is created
 * @post The minimum value is printed
 */
void BST::min(){
  minHelper(root);
}

/**
 * Recursive helper function to find the minimum value in the BST
 * 
 * @param current The current node being examined
 * @pre The BST is created
 * @post The minimum value is printed
 */
void BST::minHelper(Node *current){
  if(current->left == NULL){
    cout << "The smallest value in the BST is \"" << current->data << "\" and it appears "
	 << current->count << " times." << endl;
    return;
  }
  minHelper(current->left);
}


/**
 * Finds the maximum value in the BST
 * 
 * @pre The BST is created
 * @post The maximum value is printed
 */
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

/**
 * Recursive helper function to find the maximum value in the BST
 * 
 * @param current The current node being examined
 * @pre The BST is created
 * @post The maximum value is printed
 */
void BST::find(string word){
  string newWord = filter(word);
  bool found = false;
  findHelper(root, newWord, found);
  if (!found) {
    cout << newWord << " wasn't found in the BST." << endl;
  }
}

/**
 * Finds a specific word in the BST
 * 
 * @param word The word to search for
 * @pre The BST is created
 * @post If the word is found, it is printed with the number of occurrences
 */
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

/**
 * Sets the count for a specific word in the BST
 * 
 * @param word The word whose count to set
 * @param setCount The new count to set for the word
 * @pre The BST is created
 * @post The count of the word is set to the specified value
 */
void BST::set(string word, int setCount){
  setHelper(root,filter(word),setCount);
}

/**
 * Recursive helper function to set the count for a specific word in the BST
 * 
 * @param current The current node being examined
 * @param word The word whose count to set
 * @param setCount The new count to set for the word
 * @pre The BST is created
 * @post The count of the word is set to the specified value
 */
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


