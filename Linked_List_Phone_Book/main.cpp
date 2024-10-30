#include "Phonebook.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  Phonebook pb;
  string file = "phonebook.txt";
  pb.read_from_file(file);
  pb.print();
  cout << pb.lookup("Bob", "Bradley") << endl;
  cout << pb.lookup("Qing", "Wang") << endl;
  cout << pb.lookup("Dylan", "Daniels") << endl;
  cout << pb.lookup("Lily", "Pharris") << endl;
  cout << pb.reverse_lookup("(731)445-9783");
  pb.write_to_file("phonebookOut.txt");
  //pb.insert_sorted("Dylan", "Abba", "(777)777-777");
  pb.insert_sorted("Dylan", "Pickle", "(777)777-777");
  //pb.insert_sorted("Dylan", "Zbba", "(777)777-777");
  pb.print();
  /*
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
  */
  return 0;
}

