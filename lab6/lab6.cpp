// ASSIGNMENT NAME
// PROGRAMMER NAME
//
// DATE
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;

// This struct is complete and ready to go.
struct Item {
  string name;
  unsigned int quantity;
};

// This function is complete and ready to go.
void printItem(const Item &item) {
  cout << item.name << ", quantity: " << item.quantity << endl;
}

// You can add helper functions if you wish.

int main(int argc, char *argv[]) {

  // If a filename argument has been passed via argv,
  // attempt to open the file and read its contents.
  //
  // Absence of a filename via argv should produce an error message.
  // A non-existent file should produce an error message.
  //
  // If the file can be opened, assume that it has an unknown
  // number of lines, with each line containing a NAME:QUANTITY
  // pair. (ex., "apples:10")
  //
  // Parse each line and populate the data fields in item,
  // then pass item to the printItem function. The output
  // of the function serves as confirmation that file and data
  // processing are functioning properly.
  //
  // istringstream can help here
  // stoi() can help here

  return 0;
}
