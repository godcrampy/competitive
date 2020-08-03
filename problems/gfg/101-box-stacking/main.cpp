
/*The function takes an array of heights, width and
length as its 3 arguments where each index i value
determines the height, width, length of the ith box.
Here n is the total no of boxes.*/
int maxHeight(int height[], int width[], int length[], int n) {
  vector<vector<int>> boxes;

  for (int i = 0; i < n; ++i) {
    vector<int> temp = {height[i], width[i], length[i]};
    sort(temp.begin(), temp.end());
    // all possible dimensions
    // WLG length > height
    // L, W, H
    boxes.push_back({temp[2], temp[1], temp[0]});
    boxes.push_back({temp[2], temp[0], temp[1]});
    boxes.push_back({temp[1], temp[0], temp[2]});
  }

  // sort by area
  sort(boxes.begin(), boxes.end(), [](vector<int> a, vector<int> b) {
    return (a[0] * a[1]) > (b[0] * b[1]);
  });

  vector<int> dp(boxes.size());

  for (int i = 0; i < boxes.size(); ++i) {
    dp[i] = boxes[i][2];
  }

  for (int i = 0; i < boxes.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      auto lower = boxes[j];
      auto higher = boxes[i];
      if (higher[0] < lower[0] && higher[1] < lower[1]) {
        dp[i] = max(dp[i], dp[j] + higher[2]);
      }
    }
  }

  return *max_element(dp.begin(), dp.end());
}
