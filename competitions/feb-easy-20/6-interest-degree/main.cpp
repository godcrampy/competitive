#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  map<int, int> m;
  if (n <= 2) {
    cout << 0 << endl;
    return 0;
  }
  int temp;
  for (int i = 1; i < n; ++i) {
    cin >> temp;
    if (m.find(temp) == m.end()) {
      m.insert({temp, 0});
    } else {
      ++m[temp];
    }
  }
  if (m.size() <= 1) {
    cout << 0 << endl;
    return 0;
  }
  long long sum = 0, input;
  for (int i = 0; i < n; ++i) {
    cin >> input;
    sum += input;
  }
  cout << sum << endl;
  return 0;
}
