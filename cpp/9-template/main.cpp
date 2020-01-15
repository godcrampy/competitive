#include <iostream>
#include <map>
#include <vector>

template <typename T>
T add(T a, T b) {
  return a + b;
}

int main(int argc, char const *argv[]) {
  /* code */
  std::vector<int> test = {1, 5, 3};
  std::map<int, int> a;
  std::cout << add<int>(4.5, 5.7) << std::endl;
  return 0;
}
