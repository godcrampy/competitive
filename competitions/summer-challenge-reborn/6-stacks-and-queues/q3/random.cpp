#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  srand(time(0));

  while (n--) {
    int size = rand() % 6 + 5;
    string s;
    while (size--) {
      s += (char)(rand() % 26 + 'a');
    }
    cout << s << endl;
  }
  return 0;
}
