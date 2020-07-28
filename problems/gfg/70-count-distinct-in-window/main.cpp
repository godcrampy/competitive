
vector<int> countDistinct(int A[], int n, int k) {
  vector<int> res;
  unordered_map<int, int> m;
  int i = 0;
  for (i = 0; i < k; ++i) {
    m[A[i]]++;
  }

  res.push_back(m.size());

  for (i = k; i < n; ++i) {
    m[A[i]]++;
    m[A[i - k]]--;
    if (m[A[i - k]] <= 0) {
      m.erase(A[i - k]);
    }
    res.push_back(m.size());
  }

  return res;
}
