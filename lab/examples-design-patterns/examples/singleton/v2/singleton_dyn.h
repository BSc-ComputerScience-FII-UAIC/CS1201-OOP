#include <iostream>
using namespace std;

class Singleton {
public:
  static Singleton* instance() {
    if (uniqueInstance == nullptr) {
        uniqueInstance = new Singleton();
    }
    return uniqueInstance;
  }
  // metode care opereaza peste instanta unica
  int getValue() { return i; }
  void setValue(int x) { i = x; }
  Singleton(const Singleton&) = delete;  // copy constructor not allowed
protected:
  int i;		// campurile care descriu starea instantei
  Singleton(int x = 0) : i(x) { }   //constructor
private:
  static Singleton* uniqueInstance;  // pointer la instanta unica
};

Singleton* Singleton::uniqueInstance = nullptr;

