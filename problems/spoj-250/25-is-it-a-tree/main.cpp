#include <iostream>
#include <vector>

typedef struct node {
  int data;
  std::vector<struct node *> children;
} node;

std::vector<int> dfs(node node) {
  static std::vector<int> list = {};
  if (node.children.size() != 0) {
    for (auto child : node.children)
      dfs(*child);
  }
  list.push_back(node.data);
  return list;
}

int main() {
  std::vector<int> list;
  int number_of_nodes, number_of_edges;
  std::cin >> number_of_nodes >> number_of_edges;
  if (number_of_nodes - number_of_edges != 1)
    std::cout << "NO" << std::endl;
  else {
    std::vector<node> nodes;
    for (auto i = 0; i < number_of_nodes; ++i) {
      node temp;
      temp.data = i + 1;
      temp.children = {};
      nodes.push_back(temp);
    }
    for (auto i = 0; i < number_of_edges; ++i) {
      int a, b;
      std::cin >> a >> b;
      nodes.at(a - 1).children.push_back(&nodes.at(b - 1));
    }
    list = dfs(nodes.at(0));
  }
  if (list.size() == number_of_nodes)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
  return 0;
}
