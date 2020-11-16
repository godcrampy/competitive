#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  vector<float> sides(3, 0);
  cin >> sides[0] >> sides[1] >> sides[2];
  sort(sides.begin(), sides.end());
  float a = sides[0], b = sides[1], c = sides[2];
  if (c >= a + b || a <= 0) {
    printf("NO\n");
    return;
  }

  float p = (a + b + c) / 2;
  float area = sqrt(p * (p - a) * (p - b) * (p - c));
  area = round(area * 100000.0) / 100000.0;
  printf("YES %.5f\n", area);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
