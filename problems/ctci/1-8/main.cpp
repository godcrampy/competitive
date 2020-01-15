#include <iostream>
#include <vector>
#include <set>

using namespace std;

void zerofy_row(vector<vector<long>> &m, int index) {
  for(int j = 0; j < m[index].size(); ++j) {
    m[index][j] = 0;
  }
}

void zerofy_column(vector<vector<long>> &m, int index) {
  for(int j = 0; j < m[index].size(); ++j) {
    m[j][index] = 0;
  }
}

void zerofy_matrix(vector<vector<long>>& m) {
  set<int> rows, columns;
  for(auto i = 0; i < m.size(); ++i) {
    for(auto j = 0; j < m[i].size(); ++j) {
      if(m[i][j] == 0) {
        rows.insert(i);
        columns.insert(j);
      }
    }
  }

  for(auto i : rows) {
    zerofy_row(m, i);
  }
  for(auto i : columns) {
    zerofy_column(m, i);
  }
}

int main() {
  vector<vector<long>> m = {{1, 2, 4}, {0, 5, 6}, {7, 8, 9}};
  zerofy_matrix(m);
  for(auto v : m) {
    for(auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
