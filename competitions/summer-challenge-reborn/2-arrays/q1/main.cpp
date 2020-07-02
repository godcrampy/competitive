#include <limits.h>

#include <iostream>
#include <vector>

using namespace std;

void solve() {}

int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), s(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  long plainSum = 0;

  for (int i = 0; i < n; ++i) {
    plainSum += s[i] * a[i];
  }

  long windowSum = 0;

  for (int i = 0; i < k; ++i) {
    if (s[i] == 0) {
      windowSum += a[i];
    }
  }

  long maxWindowSum = windowSum;

  for (int i = 1; i <= n - k; ++i) {
    // * Going out
    if (s[i - 1] == 0) {
      windowSum -= a[i - 1];
    }
    if (s[i + k - 1] == 0) {
      windowSum += a[i + k - 1];
    }

    maxWindowSum = max(maxWindowSum, windowSum);
  }
  cout << maxWindowSum + plainSum << endl;
  return 0;
}
