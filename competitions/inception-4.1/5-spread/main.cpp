#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> distance(n, {0, 0});  // (distance, range)
  map<int, int> index_to_distance;
  map<int, int> distance_to_index;
  map<int, int> distance_to_sorted_index;
  map<int, int> sorted_index_to_distance;

  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    distance[i] = {d, 0};
    index_to_distance.insert({i, d});
    distance_to_index.insert({d, i});
  }

  for (int i = 0; i < n; ++i) {
    int r;
    cin >> r;
    distance[i] = {distance[i].first, r};
  }

  // sort by distance
  sort(distance.begin(), distance.end(), [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });

  for (int i = 0; i < n; ++i) {
    distance_to_sorted_index.insert({distance[i].first, i});
    sorted_index_to_distance.insert({i, distance[i].first});
  }

  // construct spread vector till wt index can spread[i] affect
  vector<int> spread(n, 1);

  for (int i = n - 2; i >= 0; --i) {
    // index of spreading
    int index = distance_to_sorted_index[index_to_distance[i]];
    int count = 1;
    int max_reach = distance[index].first + distance[index].second;
    int index_of_max_reach = i + spread[i + 1] - 1;
    if (index_of_max_reach < spread[i + 1]) {
      while (index + count < n && distance[index + count].first <= max_reach) {
        max_reach = max(max_reach, distance[index + count].first + distance[index + count].second);
        ++count;
      }
      spread[i] = distance_to_index[sorted_index_to_distance[index + count - 1]] + 1;
    } else {
      spread[i] = spread[i + 1];
    }
  }

  for (int i = 0; i < q; ++i) {
    int a;
    cin >> a;
    cout << spread[a - 1] << endl;
  }

  return 0;
}
