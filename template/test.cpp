#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int randomNumber(int l, int r) {
  // * Returns a random integer from [l, r]
  return l + (std::rand() % (r - l + 1));
}

template <typename T>
void printVector(const vector<T>& v, string msg) {
  cout << msg;
  for (auto n : v) {
    cout << n << " ";
  }
  cout << endl;
}

void smokeTest() {}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(time(0));

  smokeTest();
  return 0;
}
