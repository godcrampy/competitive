bool isBadVersion(int i);

int firstBadVersion(int n) {
  int l = 1;
  int r = n;

  while (l <= r) {
    int mid = l + (r - l) / 2;
    // found
    if (isBadVersion(mid) && (mid == 1 || !isBadVersion(mid - 1))) {
      return mid;
    } else if (isBadVersion(mid)) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return r;
}