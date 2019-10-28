#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print_min_operations_and_sequence(long n)
{
  vector<long> table(n + 1, 0);
  // Construct table;
  for (auto i = 2; i <= n; ++i)
  {
    long a = table[i - 1];
    long b = i % 2 == 0 ? table[i / 2] : __LONG_MAX__;
    long c = i % 3 == 0 ? table[i / 3] : __LONG_MAX__;
    table[i] = min(a, min(b, c)) + 1;
  }
  cout << table[n] << endl;

  // Backtrack
  stack<long> back;
  auto iterator = n;
  while (iterator != 0)
  {
    back.push(iterator);
    long a = table[iterator - 1];
    long b = iterator % 2 == 0 ? table[iterator / 2] : __LONG_MAX__;
    long c = iterator % 3 == 0 ? table[iterator / 3] : __LONG_MAX__;
    long minimun = min(a, min(b, c));
    if (minimun == a)
      --iterator;
    else if (minimun == b)
      iterator /= 2;
    else
      iterator /= 3;
  }

  while (!back.empty())
  {
    cout << back.top() << " ";
    back.pop();
  }
  cout << endl;
}

int main(int argc, char const *argv[])
{
  long n;
  cin >> n;
  print_min_operations_and_sequence(n);
  return 0;
}
