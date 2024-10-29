#include "Phonebook.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  Phonebook watchList;
  
  watchList.push_front("Brooklyn 99");
  watchList.print();
  watchList.push_front("Parks & Rec");
  watchList.print();
  watchList.push_back("Primer");
  watchList.print();
  watchList.push_front("Monty Python");
  watchList.print();
  // testing removes
  watchList.delete_user("Monty Python");
  watchList.print();

  watchList.delete_user("Brooklyn 99");
  watchList.print();

  watchList.delete_user("Primer");
  watchList.print();
  
  return 0;
}

