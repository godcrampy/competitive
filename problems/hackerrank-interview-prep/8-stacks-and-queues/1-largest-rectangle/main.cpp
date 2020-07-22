#include <bits/stdc++.h>

using namespace std;

void constructTree(const vector<int> &v, vector<pair<int, int>> &sT, int l,
                   int r, int pos) {
  if (l == r) {
    sT[pos].first = v[l];
    sT[pos].second = l;
    return;
  }

  int m = l + (r - l) / 2;
  constructTree(v, sT, l, m, pos * 2 + 1);
  constructTree(v, sT, m + 1, r, pos * 2 + 2);
  sT[pos] = min(sT[2 * pos + 1], sT[2 * pos + 2]);
}

pair<int, int> rangeMinQuery(const vector<pair<int, int>> &sT, int ql, int qr,
                             int l, int r, int pos) {
  if (ql <= l && qr >= r) {
    // total overlap
    return sT[pos];
  }

  if (ql > r || qr < l) {
    // no overlap
    return {INT_MAX, -1};
  }
  int m = l + (r - l) / 2;
  return min(rangeMinQuery(sT, ql, qr, l, m, pos * 2 + 1),
             rangeMinQuery(sT, ql, qr, m + 1, r, 2 * pos + 2));
}

long largestRectangleRec(vector<pair<int, int>> &sT, int l, int r, int vsize) {
  if (l >= r) {
    return 0;
  }
  auto p = rangeMinQuery(sT, l, r, 0, vsize, 0);
  long minVal = p.first;
  int minPos = p.second;
  return max(minVal * (r - l + 1),
             max(largestRectangleRec(sT, l, minPos - 1, vsize),
                 largestRectangleRec(sT, minPos + 1, r, vsize)));
}

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
  int n = h.size();
  vector<pair<int, int>> sT(4 * n);
  constructTree(h, sT, 0, n - 1, 0);

  return largestRectangleRec(sT, 0, n - 1, n - 1);
}
