#include <iostream>
#include <vector>

int main() {
  std::vector<int> list;
  int number_of_nodes, number_of_edges;
  std::cin >> number_of_nodes >> number_of_edges;
  int a, b;
  if (number_of_nodes - number_of_edges == 1) {
    for (auto i = 0; i <= number_of_nodes; ++i) list.push_back(i);
    for (auto i = 0; i < number_of_edges; ++i) {
      std::cin >> a >> b;
      for (auto j = 0; j <= number_of_nodes; ++j)
        if (list[j] == b) list[j] = list[a];
    }
    bool flag = true;
    for (auto i = 1; i < number_of_nodes; ++i)
      if (list[i] != list[i + 1]) {
        flag = false;
        break;
      }
    if (flag)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  } else
    std::cout << "NO" << std::endl;
  return 0;
}
