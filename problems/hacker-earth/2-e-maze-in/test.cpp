#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
  int x = 0, y = 0;
  std::string path;
  std::getline(std::cin, path);
  for (auto charecter : path)
    switch (charecter)
    {
    case ('L'):
      --x;
      break;
    case ('R'):
      ++x;
      break;
    case ('U'):
      ++y;
      break;
    case ('D'):
      --y;
      break;
    }
  std::cout << x << " " << y << std::endl;
  return 0;
}
