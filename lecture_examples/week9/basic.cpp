#include <iostream>
using namespace std;

int main() {
  // this is STATIC memory -- allocation and de-allocation are automatic
  int x(99);
  string s("Hello world");
  bool b(true);

  // DYNAMIC memory -- programmer allocates the memory, and programmer de-allocates memory
  int* pX(nullptr);

  // pX = &x;
  // *pX = 42;
  // cout << "x: " << x << endl;

  // if (pX != nullptr) {
  //   cout << "pX refers to the value: " << *pX << endl;
  // }

  if (pX == nullptr) {
    cout << "pX does not refer to anything" << endl;

    pX = new int;
    if (pX != nullptr) {
      cout << "pX now refers to something" << endl;

      // dereference pX
      *pX = 99;

      cout << "the value of pX (dereferenced): " << *pX << endl;
      cout << "the memory address of the int is: " << pX << endl;

      delete pX;
      pX = nullptr;
    }
  }  
}
