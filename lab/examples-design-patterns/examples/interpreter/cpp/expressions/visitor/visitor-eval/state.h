#ifndef STATE_H
#define STATE_H
#include <map>
#include <string>
#include <iostream>
#include "ast/ast-visitor.h"

using namespace std;

class State {
 public:
  int lookup(VarName& var) { return state[var.toString()]; }
  void update(VarName& var, int val) {
    map<string, int>::const_iterator it;
    if ((it = state.find(var.toString())) == state.end())
      {
	state.insert(pair<const string, const int>(var.toString(), val));
      }
    else state[var.toString()] = val;
  }
  
  void print() {
    map<string, int>::iterator it;
    for (it = state.begin(); it != state.end(); ++it) {
            cout << (*it).first << " |-> " << (*it).second << endl;
    }
  }
 private:
  map<string, int> state;
};
#endif
