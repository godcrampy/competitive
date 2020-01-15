#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

double distance(pair<long, long> a, pair<long, long> b) {
  return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

bool sort_by_x(pair<long, long> a, pair<long, long> b) {
  return a.first < b.first;
}

double minimum_distance_recursive(vector<pair<long, long>> points, long l, long r) {
  long mid = (l + r) / 2;
  long dmin_l = minimum_distance_recursive(points, l, mid);
  long dmin_r = minimum_distance_recursive(points, mid + 1, r);
  long d = min(dmin_l, dmin_r);
  long dmin_lr;
  // min of all points from mid - d to min + 1 + d
}

double minimum_distance(vector<pair<long, long>> points) {
  sort(points.begin(), points.end(), sort_by_x);
}