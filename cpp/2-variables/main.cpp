#include <iostream>

using namespace std;

int n {4};

int main(int argc, char const *argv[])
{
  int n = 6; // C style (Overshadows the global declaration of n)
  int a (5); // Constructor style
  float b {5.0}; // C++11 list initialization syntax (USER THIS)
  cout << sizeof a << " " << sizeof(a) << endl;
  return 0;
}
