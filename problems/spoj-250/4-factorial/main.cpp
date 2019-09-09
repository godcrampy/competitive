#include <iostream>

using namespace std;

#include "util.h"
int main()
{
  int t, number;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cin >> number;
    cout << numberOfTrailingZerosInFactorial(number) << endl;
  }
  return 0;
}
