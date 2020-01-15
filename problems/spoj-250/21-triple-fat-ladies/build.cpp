#include <iostream>

long long get_kth_cube_888(long long k) {
  int map[] = {192, 442, 692, 942};
  return ((k - 1) / 4) * 1000 + map[(k - 1) % 4];
}

int main() {
  int t;
  std::cin >> t;
  for (int _ = 0; _ < t; _++) {
    long long k;
    std::cin >> k;
    std::cout << get_kth_cube_888(k) << std::endl;
  }
  return 0;
}
