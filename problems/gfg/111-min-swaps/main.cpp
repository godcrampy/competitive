int minSwaps(int arr[], int N) {
  pair<int, int> pairs[N];

  for (int i = 0; i < N; ++i) {
    pairs[i] = {arr[i], i};
  }

  sort(pairs, pairs + N);

  bool visited[N];
  fill_n(visited, N, false);
  int res = 0;

  for (int i = 0; i < N; ++i) {
    if (visited[i] || pairs[i].second == i) continue;

    int cycleSize = 0;
    int j = i;
    // visited[i] = true;

    while (!visited[j]) {
      visited[j] = true;
      j = pairs[j].second;
      ++cycleSize;
    }

    res += max(cycleSize - 1, 0);
  }

  return res;
}
