#include <iostream>
using namespace std;

class Singleton {
public:
  static Singleton& instance() {
    return uniqueInstance;
  }
  // methods accessing the unique instance
  int getValue() { return i; }
  void setValue(int x) { i = x; }
  
  void operator=(Singleton&) = delete;	// assignment operator not allowed
  Singleton(const Singleton&) = delete;  // copy constructor not allowed
protected:
  int i;		// attributes describing the state of the unique instance
  
  Singleton(int x = 0) : i(x) { }   //constructor
private:
  static Singleton uniqueInstance;  // the unique instance
};

Singleton Singleton::uniqueInstance(47);

