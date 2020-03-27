#include <vector>

using namespace std;

int volume(const vector<int>& height, int i, int j) {
  return min(height[i], height[j]) * (j - i);
}
int maxArea(vector<int>& height) {
  int i = 0;
  int j = height.size() - 1;
  int max_volume = volume(height, i, j);

  while (i < j) {
    // move the smaller guy
    if (height[i] < height[j]) {
      // move i
      ++i;
      max_volume = max(max_volume, volume(height, i, j));
    } else {
      // move j
      --j;
      max_volume = max(max_volume, volume(height, i, j));
    }
  }

  return max_volume;
}