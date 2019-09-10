#include <iostream>
#include <cstring>
#include <cctype>

int main(int argc, char const *argv[])
{
  char first_name[50]{};
  char last_name[50]{};
  char full_name[100]{};
  std::cout << "Enter First Name: " << std::endl;
  std::cin >> first_name;
  std::cout << "Enter Last Name: " << std::endl;
  std::cin >> last_name;

  std::strcpy(full_name, first_name);
  std::strcat(full_name, " ");
  std::strcat(full_name, last_name);

  std::string test;

  std::getline(std::cin, test);

  std::cout << full_name << std::endl;
  return 0;
}
