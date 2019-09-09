#include <iostream>
#include <vector>

using namespace std;

auto printVector(vector<int> vector)
{
  for (int number : vector)
    cout << number << " ";
  cout << endl;
}

int main(int argc, char const *argv[])
{
  vector<int> vec = {1, 2, 3, 4, 5};
  printVector(vec);
  return 0;
}
