#include <iostream>
#include <vector>

std::ostream &operator<<(std::ostream &stream, std::vector<int> vector)
{
  stream << "[";
  for (auto item : vector)
    stream << item << ", ";
  stream << "\b\b";
  stream << "]";
  return stream;
}

std::istream &operator>>(std::istream &stream, std::vector<int> vector)
{
  int temp;
  while (stream >> temp)
  {
    if (temp == 0)
      break;
    vector.push_back(temp);
  }
  return stream;
}

int main(int argc, char const *argv[])
{
  std::vector<int> a = {1, 4, 5, 1, 3, 2};
  std::cin >> a;
  std::cout << a << std::endl;
  return 0;
}
