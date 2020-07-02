#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

bool smaller(pair<int, char> a, pair<int, char> b) {
  return a.first < b.first;
}

auto points_frequency(vector<long> points, vector<pair<long, long>> segments) {
  int s = segments.size();
  int p = points.size();
  vector<pair<long, char>> points_map(2 * s + p, {0, 'a'});
  for (int i = 0; i < 2 * s; i = i + 2) {
    points_map[i] = {segments[i / 2].first, 'l'};
    points_map[i + 1] = {segments[i / 2].second, 'r'};
  }
  for (int i = 0; i < p; ++i) {
    points_map[i + 2 * s] = {points[i], 'p'};
  }
  sort(points_map.begin(), points_map.end(), smaller);
  map<long, int> frequence_count;
  for (auto point : points)
    frequence_count.insert({point, 0});
  int depth = 0;
  for (auto point : points_map) {
    switch (point.second) {
      case 'l':
        ++depth;
        break;
      case 'r':
        --depth;
        break;
      default:
        // case 'p'
        frequence_count[point.first] = depth;
        break;
    }
  }
  for (auto point : points)
    cout << frequence_count[point] << " ";
  cout << endl;
}

int main(int argc, char const *argv[]) {
  int s, p;
  cin >> s >> p;
  vector<pair<long, long>> segments(s, {0, 0});
  for (auto i = 0; i < s; ++i) {
    long a, b;
    cin >> a >> b;
    segments[i] = {a, b};
  }
  vector<long> points(p, 0);
  for (auto i = 0; i < p; ++i) {
    cin >> points[i];
  }
  points_frequency(points, segments);
  return 0;
}
