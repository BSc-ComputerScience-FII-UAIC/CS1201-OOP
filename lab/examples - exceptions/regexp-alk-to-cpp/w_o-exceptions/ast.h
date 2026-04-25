#include <string>
#include <vector>
#include <algorithm> 
#include <iostream>

using namespace std;

class Ast {
 public:
  virtual int size() = 0;
  virtual int chldNo() = 0;
  virtual Ast* child(int i) = 0;
  virtual void print() = 0;
};

class AstEmpty : public Ast {
 public:
  AstEmpty() {}
  int size() { return 0;}
  void print() {
    cout << "[]";
  }
  int chldNo() {
    return -1; //??
  }
  Ast* child(int i) {
    return new AstEmpty; //??
  }
};

class AstNonEmpty : public Ast {
 private:
  string label;
  vector<Ast*> children;

 public:
  AstNonEmpty(string aLabel = "",
              vector<Ast*> aList = vector<Ast*>())
    {
      label = aLabel;
      children = aList;
    }

  int size() {
    return chldNo() + 1;
  }
  
  int chldNo() {
    return children.size();
  }

  Ast* child(int i); 

  void print();
};
