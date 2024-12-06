/**
 * @file driver.cpp
 * @author Dylan Daniels
 * @date 2024-12-05
 * @brief driver function
 * 
 * Is the file for showing my implemetation of the BST ADT
 */

#include <iostream>
#include "bst.h"
using namespace std;

int main() {
  BST tree;
  int choice, count;
  string filename, word;
  do {
    cout << "+---------------------------------------------------+\n" 
	 << "1. Load the BST from a text file.\n"
	 << "2. Save the BST to a text file.\n"
         << "3. Insert a element into the BST.\n"
         << "4. Print the BST.\n"
         << "5. Search for how many times a word is in the BST.\n"
         << "6. Show the largest value in the BST\n"
         << "7. Show the smallest value in the BST.\n"
         << "8. Update the data of a element.\n"
	 << "9. Delete a element.\n"
         << "10. Exit this program.\n";
    cin >> choice;
    cout << endl;
    
    switch(choice){
    case 1:{
      cout << "Please enter the file to read from: ";
      cin >> filename;
      tree.readFile(filename);
      break;
    } // load
    case 2:{
      cout << "Please enter the file to write to: ";
      cin >> filename;
      tree.writeFile(filename);
    break;} // write
    case 3:{
      cout << "What word would you like to add to the BST: ";
      cin >> word;
      tree.insert(word);
      cout << "Item inserted!" << endl;
      break;
    } // insert
    case 4:{
      cout << "Printing BST: " << endl;
      tree.print();
      break;
    } // print
    case 5:{
      cout << "What would you like to search for in the BST: ";
      cin >> word;
      tree.find(word);
      break;
	} // lookup / find
    case 6:{
      cout << "Serching for the largest value in the BST: \n";
      tree.max();
      break;
    } // max
    case 7:{
      cout << "Serching for the largest value in the BST: \n";
      tree.min();
      break;
    } // min
    case 8:{
      cout << "What word would you like to add / modify: ";
      cin >> word;
      cout << "What do you wish this value to be?";
      cin >> count;
      tree.set(word, count);
      break;
    } // set
    case 9:{
      cout << "What element would you like to delete from the BST: ";
      cin >> word;
      tree.deleteNode(word);
      break;
    }//delete
    case 10:{
      cout << "Exiting the program. Goodbye!" << endl;
      break;
    } // exit
    default: {
      cout << "Invalid choice. Please try again." << endl;
      break;
    }
    }
  } while (choice != 10);
  return 0;
}
