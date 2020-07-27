int maxLen(int A[], int n) {
  vector<int> prefixSum(n + 1, 0);
  unordered_map<int, set<int>> m;  // prefixSum To Index
  for (int i = 1; i <= n; ++i) {
    prefixSum[i] = prefixSum[i - 1] + A[i - 1];
    m[prefixSum[i]].insert(i);
  }

  int maxLength = 0;
  for (int i = 0; i <= n; ++i) {
    if (prefixSum[i] == 0) {
      maxLength = max(maxLength, i);
    } else {
      int j = *m[prefixSum[i]].begin();
      maxLength = max(maxLength, i - j);
    }
  }

  return maxLength;
}
