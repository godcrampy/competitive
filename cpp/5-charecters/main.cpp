#include <cctype>
#include <iostream>

int main(int argc, char const *argv[])
{
  char a;
  // NOTE: The following functions are called without the std namespace.
  // They work too with the std namespace: std::isaplha(a)
  // This is because the <cctype> has two declarations one for c and other c++
  // The following use case is using the c functions
  // Ideally std::function_name() should have been used
  std::cin >> a;
  std::cout << "isaplha: " << static_cast<bool>(isalpha(a)) << std::endl;    // Is Alphabet
  std::cout << "isdigit: " << static_cast<bool>(isdigit(a)) << std::endl;    // Is digit
  std::cout << "isaplhanum: " << static_cast<bool>(isalnum(a)) << std::endl; // Is alphanumeric
  std::cout << "isupper: " << static_cast<bool>(isupper(a)) << std::endl;    // Uppercase
  std::cout << "islower: " << static_cast<bool>(islower(a)) << std::endl;    // lowercase
  std::cout << "isprint: " << static_cast<bool>(isprint(a)) << std::endl;    // is printable
  std::cout << "ispunct: " << static_cast<bool>(ispunct(a)) << std::endl;    // punctuation
  std::cout << "isspace: " << static_cast<bool>(isspace(a)) << std::endl;    // punctuation

  return 0;
}
