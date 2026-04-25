#include<iostream>
#include <string>
#include <regex>

int main(void) {
  try {
    std::regex re("[a-z]*[a");
  } 
  catch (const std::regex_error& e) {
    std::cout << "regex_error caught: " << e.what() << '\n';
    if (e.code() == std::regex_constants::error_brack) {
      std::cout << "The code was error_brack\n";
    }
  }
  return 0;
}
