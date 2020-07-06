#include <bits/stdc++.h>

using namespace std;

int getRoot(const vector<int> &dS, int i) {
  while (i != dS[i]) {
    i = dS[i];
  }
  return i;
}

int join(vector<int> &ds, vector<int> &maxGroup, int i, int j, int maxSize) {
  int ri = getRoot(ds, i);
  int rj = getRoot(ds, j);
  if (ri == rj) {
    return maxSize;
  }

  if (ri < rj) {
    // rj is no more root
    ds[rj] = ri;
    maxGroup[ri] += maxGroup[rj];
    return max(maxGroup[ri], maxSize);
  } else {
    // ri is no more root
    ds[ri] = rj;
    maxGroup[rj] += maxGroup[ri];
    return max(maxGroup[rj], maxSize);
  }
}

// Complete the maxCircle function below.
vector<int> maxCircle(vector<vector<int>> queries) {
  // map coordinates to minimum numbers
  set<int> store;
  unordered_map<int, int> m;  // original number -> new number

  for (auto v : queries) {
    store.insert(v[0]);
    store.insert(v[1]);
  }
  int x = 0;
  for (int n : store) {
    m[n] = x++;
  }

  for (auto &v : queries) {
    v[0] = m[v[0]];
    v[1] = m[v[1]];
  }

  int peopleCount = store.size();
  vector<int> maxGroup(peopleCount), ds(peopleCount);

  for (int i = 0; i < peopleCount; ++i) {
    ds[i] = i;
    maxGroup[i] = 1;
  }
  int maxSoFar = -1;
  vector<int> res;
  for (auto &v : queries) {
    int temp = join(ds, maxGroup, v[0], v[1], maxSoFar);
    maxSoFar = max(maxSoFar, temp);
    res.push_back(temp);
  }

  return res;
}
