#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  map<int, int> max_for_color;

  vector<int> vec(n, 0), clr(n, 1);
  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }

  int max_clr = 1;
  max_for_color.insert({1, vec[0]});
  for (int i = 1; i < n; ++i) {
    bool skip = false;
    for (int k = 1; k <= max_for_color.size(); ++k) {
      if (vec[i] > max_for_color[k]) {
        clr[i] = k;
        max_clr = max(max_clr, clr[i]);
        max_for_color[k] = vec[i];
        skip = true;
        break;
      }
    }
    if (!skip) {
      ++max_clr;
      clr[i] = max_clr;
      max_for_color.insert({vec[i], max_clr});
    }
  }
  cout << max_clr << endl;
  return 0;
}
