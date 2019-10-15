#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

typedef struct item
{
  int weight;
  int value;
  item(int weight, int value) : weight(weight), value(value){};
  bool operator>(const item &item2) const
  {
    return (static_cast<double>(value) / weight) > (static_cast<double>(item2.value) / item2.weight);
  }
} item;

double maximum_value(std::vector<int> weights, std::vector<int> values, int weight_limit)
{
  std::vector<item> weight_and_values;
  for (auto i = 0; i < weights.size(); ++i)
    weight_and_values.push_back(item(weights[i], values[i]));
  std::sort(weight_and_values.begin(), weight_and_values.end(), std::greater<item>());
  double value = 0;
  auto iterator = weight_and_values.begin();
  // correct till here
  while (weight_limit > 0)
  {
    if (iterator->weight <= weight_limit)
    {
      // item can be fit into full
      value += iterator->value;
      weight_limit -= iterator->weight;
    }
    else
    {
      // item can be fit partially
      value += static_cast<double>(iterator->value) * weight_limit / iterator->weight;
      weight_limit = 0;
    }
    ++iterator;
  }
  return value;
}

int main(int argc, char const *argv[])
{
  int size, limit;
  std::cin >> size >> limit;
  std::vector<int> weights, values;
  for (int i = 0; i < size; ++i)
  {
    int w, v;
    std::cin >> v >> w;
    weights.push_back(w);
    values.push_back(v);
  }
  std::cout << std::fixed << std::setprecision(4) << maximum_value(weights, values, limit) << std::endl;
  return 0;
}
