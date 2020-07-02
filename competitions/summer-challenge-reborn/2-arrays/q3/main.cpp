#include <iostream>
#include <vector>

using namespace std;

const long alpha = 1000000007;

pair<int, int> getAandB(const vector<int> &v, int position) {
  int a = 0, b = 0;
  int n = v[position];
  for (int i = 0; i < v.size(); ++i) {
    if (n > v[i]) {
      ++b;
      if (i > position) {
        ++a;
      }
    }
  }

  return {a, b};
}

int main(int argc, char const *argv[]) {
  long long n, k;
  cin >> n >> k;
  vector<int> vec(n);

  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }

  long long count = 0;

  for (int i = 0; i < n; ++i) {
    auto p = getAandB(vec, i);
    int a = p.first;
    int b = p.second;
    count = (count +
             ((k * a) % alpha + (((((k) * (k - 1)) / 2) % alpha) * b) % alpha) %
                 alpha) %
            alpha;
  }

  cout << count % alpha << endl;
  return 0;
}
