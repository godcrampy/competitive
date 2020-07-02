#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

// ! IMP

bool get_path(vector<vector<bool>> m, int r, int c,
              set<pair<int, int>> &failed_points,
              vector<pair<int, int>> &path) {
  if (r == 0 && c == 0) {
    path.push_back({r, c});
    return true;
  }

  if (c < 0 || r < 0 || !m[r][c]) {
    return false;
  }

  if (failed_points.find({r, c}) != failed_points.end()) {
    return false;
  }

  if (get_path(m, r - 1, c, failed_points, path) ||
      get_path(m, r, c - 1, failed_points, path)) {
    path.push_back({r, c});
    return true;
  }

  failed_points.insert({r, c});
  return false;
}

vector<pair<int, int>> get_path(vector<vector<bool>> matrix) {
  // * Time: O(RC)
  // * Space: O(RC)
  set<pair<int, int>> failed_points;
  vector<pair<int, int>> path;
  if (get_path(matrix, matrix.size() - 1, matrix[0].size() - 1, failed_points,
               path)) {
    return path;
  }
  return {};
}

int main(int argc, char const *argv[]) {
  vector<vector<bool>> m = {
      {true, true, true},
      {false, false, false},
      {true, false, true},
  };
  auto v = get_path(m);
  for (auto p : v) {
    cout << p.first << " " << p.second << endl;
  }
  return 0;
}
