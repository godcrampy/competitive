// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/a-game-of-numbers-1-5d3a8cb3/
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<long long> nums(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  vector<int> next_biggest(n, -1);
  vector<int> next_smallest(n, -1);
  for (int i = 0; i < n; ++i) {
    bool b_set = false, s_set = false;
    for (int j = i + 1; j < n; ++j) {
      if (!b_set && nums[j] > nums[i]) {
        next_biggest[i] = j;
        b_set = true;
      }
      if (!s_set && nums[j] < nums[i]) {
        next_smallest[i] = j;
        s_set = true;
      }
      if (s_set && b_set) {
        break;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (next_biggest[i] == -1 || next_smallest[next_biggest[i]] == -1) {
      cout << -1 << " ";
      continue;
    }
    cout << nums[next_smallest[next_biggest[i]]] << " ";
  }
  cout << endl;
  return 0;
}
