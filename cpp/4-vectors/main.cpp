#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vector)
{
  for (auto i = vector.begin(); i != vector.end(); ++i)
    cout << *i << " ";
  cout << endl;
}

void initializeVector(vector<int> &a)
{
  int count{0};
  for (auto i = a.begin(); i != a.end(); ++i)
  {
    *i = count++;
  }
}

void printReverse(vector<int> a)
{
  for (auto i = a.rbegin(); i != a.rend(); ++i)
    cout << *i << " ";
  cout << endl;
}

int main(int argc, char const *argv[])
{
  vector<int> a(5);
  printVector(a);
  initializeVector(a);
  printVector(a);
  printReverse(a);

  cout << "Vector Size: " << a.size() << endl;
  cout << "Vector Access: " << *(a.begin() + 1) << endl;
  cout << "Vector Access: " << a[1] << endl;
  cout << "Vector Access: " << a.at(1) << endl;

  a.push_back(99);
  printVector(a);
  a.pop_back();
  printVector(a);
  return 0;
}
