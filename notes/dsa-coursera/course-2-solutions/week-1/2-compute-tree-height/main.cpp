#include <vector>
#include <iostream>

typedef struct node
{
  std::vector<node *> children;
  node() : children({}){};
} node;

int cout_height(node *node)
{
  if (node->children.size() == 0)
    return 1;
  int max_height = 0;
  for (auto child : node->children)
  {
    max_height = std::max(max_height, cout_height(child));
  }
  return 1 + max_height;
}

int tree_height(std::vector<int> &map)
{
  // construct the tree
  auto map_size = map.size();
  // make a vector of addresses
  std::vector<node *> addresses(map_size, nullptr);
  node *root = nullptr;
  for (auto i = 0; i < map_size; ++i)
  {
    addresses[i] = new node();
  }
  // for each node address, make connections
  for (auto i = 0; i < map_size; ++i)
  {
    if (map[i] == -1)
      root = addresses[i];
    else
    {
      addresses[map[i]]->children.push_back(addresses[i]);
    }
  }
  return cout_height(root);
}

int main(int argc, char const *argv[])
{
  int n;
  std::cin >> n;
  std::vector<int> map(n, 0);
  for (auto i = 0; i < n; ++i)
    std::cin >> map[i];
  std::cout << tree_height(map) << std::endl;
  return 0;
}
