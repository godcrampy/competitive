#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int input{0};
  while (true) {
    cin >> input;
    if (input == 42)
      break;
    cout << input << endl;
  }
  return 0;
}
