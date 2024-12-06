/**
 * @file bst.h
 * @author Dylan Daniels
 * @date 2024-12-05
 * @brief header file for BST word count
 * 
 * contains all of the functions for BST class and nodes
 */

#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;


/**
 * node class for binary search tree
 *
 * @class Node bst.h "BST_Word_Counting/bst.h"
 * @brief a singular node in the bst
 *
 */
class Node {
 public:
  Node(string value);
  Node *left, *right;
  string data;
  int count;
};

/**
 * binary search tree class
 *
 * @class BST bst.h "BST_Word_Counting/bst.h"
 * @brief class that is made up of nodes to build a binary search tree
 *
 */
class BST {

private:
  Node *root;

 /**
* helper function to recursively insert a new node into the tree
*
* @param current the current node being checked
* @param value the string value to insert into the tree
* @pre BST is created
* @post the value is inserted into the appropriate location in the tree
* 
*/
  void insertHelper(Node *current, string value);

 /**
* helper function to recursively print the tree
*
* @param current the current node being printed
* @pre BST is created
* @post the entire tree is printed in a structured format
* 
*/
  void printHelper(Node *current);

 /**
* helper function to recursively deallocate memory for nodes in the tree
*
* @param Node* current the current node to delete 
* @pre BST is created
* @post deallocates memory for the current node and its childern
* 
*/
  void destructorHelper(Node* current);

  /**
 * helper function to delete a node with a specific value from the tree
 *
 * @param current the current node being examined
 * @param value the value of the node to delete
 * @pre BST is created
 * @post removes the node with the specified value and restructures the tree accordingly
 * 
 */
  void deleteHelper(Node* &current, string value);

  /**
 * helper function to find the minimum value node in the tree
 *
 * @param current the current node being checked
 * @pre BST is created
 * @post traverses the tree to find the leftmost (minimum) node
 * 
 */
  void minHelper(Node *current);

  /**
 * helper function to find the maximum value node in the tree
 *
 * @param current the current node being checked
 * @pre BST is created
 * @post traverses the tree to find the rightmost (maximum) node
 * 
 */
  void maxHelper(Node *current);

  /**
 * helper function to write the tree data to a file
 *
 * @param ofile the output file stream to write to
 * @param current the current node being written
 * @pre BST is created and ofile is open for writing
 * @post writes the tree data to the specified file
 * 
 */
  void writeHelper(ofstream& ofile, Node *current);

 /**
 * helper function to set the count of a specific word in the tree
 *
 * @param current the current node being checked
 * @param word the word to set the count for
 * @param count the count to set for the word
 * @pre BST is created
 * @post sets the count for the specified word in the tree node
 * 
 */
  void setHelper(Node *current, string word, int count);

 /**
 * helper function to search for a specific word in the tree
 *
 * @param current the current node being checked
 * @param word the word to find
 * @param found reference to a boolean flag indicating whether the word is found
 * @pre BST is created
 * @post updates the found flag to true if the word is found, false otherwise
 * 
 */
  void findHelper(Node *current, string word, bool &found);

 /**
 * helper function to filter out unwanted characters from a string
 *
 * @param word the string to filter
 * @pre word is a string containing potential unwanted characters
 * @return the filtered version of the string
 * @post returns a string with unwanted characters removed
 * 
 */
  string filter(string word);
public:

 /**
 * constructor for BST class
 *
 * @pre BST is created
 * @post initializes the root pointer to null
 * 
 */
  BST();

 /**
 * destructor for BST class
 *
 * @pre BST is created
 * @post deallocates all memory used by the BST
 * 
 */
  ~BST();

 /**
 * inserts a new value into the binary search tree
 *
 * @param value the string value to insert into the tree
 * @pre BST is created
 * @post the value is inserted into the correct position in the tree
 * 
 */
  void insert(string value);

 /**
 * sets a value for a specific word in the tree
 *
 * @param word the word to associate with a value
 * @param value the value to set for the word
 * @pre BST is created
 * @post associates the specified word with the provided value
 * 
 */
  void set(string word, string value);

 /**
 * prints the minimum value in the tree
 *
 * @pre BST is created
 * @post prints the minimum value in the tree
 * 
 */
  void min();
  
 /**
 * prints the maximum value in the tree
 *
 * @pre BST is created
 * @post prints the maximum value in the tree
 * 
 */
  void max();

 /**
 * sets a count for a specific word in the tree
 *
 * @param word the word to set the count for
 * @param setCount the count to set for the word
 * @pre BST is created
 * @post sets the specified count for the given word
 * 
 */
  void set(string word, int setCount);

 /**
 * prints the entire tree
 *
 * @pre BST is created
 * @post prints all the nodes in the tree
 * 
 */
  void print();
  
 /**
 * finds a word in the tree
 *
 * @param word the word to search for in the tree
 * @pre BST is created
 * @post prints whether the word is found or not
 * 
 */
  void find(string word);
  
 /**
 * writes the tree data to a file
 *
 * @param filename the name of the file to write the tree data to
 * @pre BST is created and filename is valid
 * @post writes the tree data to the specified file
 * 
 */
  void writeFile(string filename);
  
 /**
 * reads tree data from a file
 *
 * @param filename the name of the file to read data from
 * @pre BST is created and filename is valid
 * @post loads data from the file into the tree
 * 
 */
  void readFile(string filename);
  
 /**
 * deletes a node with a specific value from the tree
 *
 * @param value the value of the node to delete
 * @pre BST is created
 * @post removes the node with the specified value and restructures the tree
 * 
 */
  void deleteNode(string value);
  
};

#endif //BST_H
