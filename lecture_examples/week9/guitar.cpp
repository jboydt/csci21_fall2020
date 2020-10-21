#include <iostream>
#include <string>
using namespace std;

struct Guitar {
  string brand;
  unsigned int numStrings;
  bool isAcoustic;

  // default CONSTRUCTOR
  Guitar() {
    cout << "Guitar CREATED" << endl;
  }

  // DESTRUCTOR
  ~Guitar() {
    cout << "Guitar DESTROYED" << endl;
  }

  void print() {
    cout << brand << ", has " << numStrings << " strings" << endl;
  }
};

void goGuitar() {
  Guitar* pG(nullptr);
  pG = new Guitar;

  (*pG).brand = "Gibson";
  pG->numStrings = 6;

  //cout << "The brand is " << (*pG).brand << endl;
  //cout << "It has " << pG->numStrings << " strings" << endl;

  (*pG).print();
  pG->print();

  delete pG;
  pG = nullptr;
}

int main() {
  cout << "Starting" << endl;
  goGuitar();
  cout << "Ending" << endl;
}
