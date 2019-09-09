#include <iostream>

using namespace std;

long get_max(long number)
{
  if (number < 12)
    return number;
  if (number / 2 + number / 3 + number / 4 > number)
    return get_max(number / 2) + get_max(number / 3) + get_max(number / 4);
  return number;
}

int main(int argc, char const *argv[])
{
  long n;
  while (cin >> n)
    cout << get_max(n) << endl;
  return 0;
}
