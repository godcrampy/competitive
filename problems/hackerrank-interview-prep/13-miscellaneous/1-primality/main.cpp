#include <bits/stdc++.h>

using namespace std;

// Complete the primality function below.
string primality(int n) {
  if (n == 2) {
    return "Prime";
  }
  if (n == 1) {
    return "Not prime";
  }
  int sq = sqrt(n) + 1;
  for (int i = 2; i <= sq; ++i) {
    if (n % i == 0) {
      return "Not prime";
    }
  }
  return "Prime";
}
