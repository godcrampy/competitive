/**
 * Implementation of rank and parent
 */
#include <iostream>
#include <vector>

using namespace std;

void makeSet(int i, vector<int>& parent, vector<int>& rank);
int find(int x, vector<int>& parent);
void makeUnion(int x, int y, vector<int>& parent, vector<int>& rank);

int main(int argc, char const* argv[]) {
  /* code */
  vector<int> parent(8, 0);
  vector<int> rank(8, 0);
  for (int i = 0; i < 8; ++i) {
    makeSet(i, parent, rank);
  }
  makeUnion(0, 7, parent, rank);
  makeUnion(1, 2, parent, rank);
  makeUnion(4, 1, parent, rank);
  makeUnion(2, 7, parent, rank);
  makeUnion(3, 7, parent, rank);
  cout << find(4, parent) << endl;
  cout << find(0, parent) << endl;
  cout << find(7, parent) << endl;
  cout << find(3, parent) << endl;
  cout << find(5, parent) << endl;
  return 0;
}

void makeSet(int i, vector<int>& parent, vector<int>& rank) {
  parent[i] = i;
  rank[i] = 0;
}

int find(int x, vector<int>& parent) {
  int i = parent[x];
  while (i != parent[i]) {
    i = parent[i];
  }
  return i;
}

void makeUnion(int x, int y, vector<int>& parent, vector<int>& rank) {
  int x_id = find(x, parent);
  int y_id = find(y, parent);
  if (x_id == y_id) {
    return;
  }
  if (rank[x_id] > rank[y_id]) {
    parent[y_id] = x_id;
  } else {
    parent[x_id] = y_id;
    if (rank[x_id] == rank[y_id]) {
      rank[y_id]++;
    }
  }
}
