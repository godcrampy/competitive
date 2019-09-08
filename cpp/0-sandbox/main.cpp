#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vector)
{
  for (auto i = vector.begin(); i != vector.end(); ++i)
    cout << *i << " ";
  cout << endl;
}

void printVector(vector<vector<int>> vector)
{
  for (int i = 0; i < vector.size(); i++)
    printVector(vector.at(i));
}

auto printVectorRangeBased(vector<int> vector)
{
  for (auto i : vector)
    cout << i << " ";
  cout << endl;
}

int main(int argc, char const *argv[])
{
  vector<int> vector1;
  vector<int> vector2;
  vector1.push_back(10);
  vector1.push_back(20);

  vector2.push_back(100);
  vector2.push_back(200);

  printVectorRangeBased(vector1);
  printVector(vector2);

  vector<vector<int>> vector_2d;

  vector_2d.push_back(vector1);
  vector_2d.push_back(vector1);

  printVector(vector_2d);

  vector1.at(0) = 1000;

  printVector(vector_2d);

  cout << *vector2.end() << endl;
  return 0;
}
