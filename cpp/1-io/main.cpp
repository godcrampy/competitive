#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  float a, b;
  char name[50];

  cin >> a;
  cin >> a;
  cin >> a;
  cin >> a;

  // cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getchar();

  cin.getline(name, 50);
  cout << a << endl;
  cout << name;

  return 0;
}
