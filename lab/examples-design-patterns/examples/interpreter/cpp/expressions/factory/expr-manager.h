#ifndef _EXPR_MANAGER_H
#define _EXPR_MANAGER_H
#include <iostream>

#include "registrar.h"

class ExprManager {
 public:
  static Expression* loadf(ifstream& f, Registrar& reg) {
    if (f.eof())
      throw "Unknown file.";
    string tag;
    f >> tag;
    return loadfRec(f, reg, tag);
  }

  static Expression* loadfRec(ifstream& f, Registrar& reg, string tag) {
    Expression* expr1 = reg.createExpr(tag);
    string endTag = tag.insert(1,"/");
    Expression* expr2;
    if (expr1->getCompoundExpression()) {
      if (f.eof())
	throw "File illformatted.";
      // read the label info
      string labelInfo;
      f >> labelInfo;
      f >> labelInfo;
      expr1->setLabel(toLabel(labelInfo));
      f >> labelInfo;
      // read the next tag
      string nextTag;
      f >> nextTag;
      while (endTag != nextTag && !f.eof()) {
	expr2 = loadfRec(f, reg, nextTag);
	expr1->addChild(expr2);
	f >> nextTag;
      }
    }
    else { 
      if (f.eof())
	throw "File illformatted.";
      expr1->loadInfo(f);
      if (f.eof())
	throw "File illformatted.";
      f >> tag;
    }
    return expr1;
  }
 private: static list<string> toLabel(string labelInfo) {
    list<string> label;
    string str;
    int pos = labelInfo.find_first_of('[');
    if (pos == string::npos) return label;
    labelInfo.erase(pos);
    pos = labelInfo.find_first_of(',');
    if (pos != string::npos) {
      do {
    	str = labelInfo.substr(pos);
    	labelInfo.erase(pos);
    	label.push_back(str);
    	pos = labelInfo.find_first_of(',');
      } while (pos != string::npos);
    }
    pos = labelInfo.find_first_of(']');
    if (pos == string::npos) return label;
    str = labelInfo.substr(pos);
    label.push_back(str);
    return label;
  }
};

#endif
