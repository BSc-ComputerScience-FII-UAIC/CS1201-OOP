class MyException {
 public:
  virtual void debugPrint() {
    std::cout << "Exception: ";
  }
};

class AstException : public MyException {
 public:
  virtual void debugPrint() {
    this->MyException::debugPrint();
    std::cout << "AST: ";
  }
};

class EmptyAstException : public AstException {
 public:
  virtual void debugPrint() {
    this->AstException::debugPrint();
    std::cout << "trying to access an empty tree.";
  }
};

class NonEmptyAstException : public AstException {
 private:
  int badIndex;
 public:
  void setBadIndex(int j) {
    badIndex = j;
  }
  virtual void debugPrint() {
    this->AstException::debugPrint();
    std::cout << "index out of bounds (" << badIndex << ").\n";
  }
};


class ParserException : public MyException {
 public:
 private:
  int badPos;
  std::string errMsg;
 public:
  void setBadPos(int j) {
    badPos = j;
  }
  void setErrMsg(std::string msg) {
    errMsg = msg;
  }
  virtual void debugPrint() {
    this->MyException::debugPrint();
    std::cout << "Parsing: " << errMsg
	      << " at input position " << badPos << ".\n";
  }
};

