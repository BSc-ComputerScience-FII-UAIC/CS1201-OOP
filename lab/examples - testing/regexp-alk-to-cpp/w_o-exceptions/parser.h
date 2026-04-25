#include <string>
#include <vector>
#include <algorithm> 
#include <iostream>
#include "ast.h"

using namespace std;

class Parser {
 private:
  string input;
  vector<char> sigma;
  int index;
 public:
  Parser(vector<char> alphabet = vector<char>()) {
    sigma = alphabet;
    input = "";
    index = 0;
  }

  void setInput(string str) {
    input = str;
  }

  void error (string msg) {
    cout << endl << "ERROR: " << msg << " at position " << index;
  }

  char sym() {
    if (index < input.size()) {
      return input[index];
    }
    return '\0';
  }

  void nextSym();

  bool accept(char s) {
    if (sym() == s) {
      nextSym();
      return true;
    }
    return false;
  }

  bool acceptSigma() {
    for (int i = 0; i < sigma.size(); ++i) {
      if (accept(sigma[i])) {
	return true;
      }
    }
    return false;
  }

  bool expect(char s);

  Ast* factor();

  Ast* maybeStar();

  Ast* term();

  Ast* expression();
};
