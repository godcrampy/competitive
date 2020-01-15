#include <math.h>
#include <iostream>

using namespace std;

int isPrime(int number) {
  if (number == 1)
    return 0;
  for (int i = 2; i <= sqrt(number); i++)
    if (number % i == 0)
      return 0;
  return 1;
}

int main(int argc, char const *argv[]) {
  int t, m, n;
  cin >> t;
  for (int _ = 0; _ < t; ++_) {
    cin >> m >> n;
    for (int i = m; i <= n; i++) {
      if (isPrime(i))
        cout << i << endl;
    }
    cout << endl;
  }
  return 0;
}
