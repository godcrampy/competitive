#include <algorithm>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int total_length = nums1.size() + nums2.size();
  vector<int> merged_vec(total_length, 0);

  merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),
        merged_vec.begin());

  if (total_length % 2 == 0) {
    // 0 1 2 3
    return ((double)(merged_vec[total_length / 2] +
                     merged_vec[total_length / 2 - 1])) /
           2;
  }
  // 0 1 2 3 4
  return merged_vec[total_length / 2];
}