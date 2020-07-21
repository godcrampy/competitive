#include <bits/stdc++.h>

using namespace std;

int root(vector<int> &ds, int a) {
  while (ds[a] != a) {
    a = ds[a];
  }
  return a;
}

void unionDS(vector<int> &ds, int a, int b) {
  int ra = root(ds, a), rb = root(ds, b);
  if (ra < rb) {
    ds[rb] = ra;
  } else {
    ds[ra] = rb;
  }
}

bool find(vector<int> &ds, int a, int b) { return root(ds, a) == root(ds, b); }

// Complete the minTime function below.
int minTime(vector<vector<int>> roads, vector<int> machines) {
  int n = roads.size() + 1;
  vector<int> ds(n);
  for (int i = 0; i < n; ++i) {
    ds[i] = i;
  }

  // join machines
  for (int machine : machines) {
    unionDS(ds, machine, machines[0]);
  }

  sort(roads.begin(), roads.end(),
       [](vector<int> a, vector<int> b) { return a[2] >= b[2]; });
  // iterate

  int cost = 0;
  for (auto v : roads) {
    // if both of them belongs to machine, don't join and add to cose
    if (find(ds, v[0], machines[0]) && find(ds, v[1], machines[0])) {
      cost += v[2];
    } else {
      unionDS(ds, v[0], v[1]);
    }
    // else join
  }

  return cost;
}
