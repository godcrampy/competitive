#include <iostream>
#include <vector>

int number_of_stops(int range, std::vector<int> stops) {
  int current_index = 0, number_of_stops = 0, total_stops = stops.size();
  while (current_index < total_stops) {
    int previous_index = current_index;
    while (stops[current_index] - stops[previous_index] <= range &&
           current_index != total_stops)
      ++current_index;
    if (current_index == total_stops) return number_of_stops;
    if (current_index - previous_index == 1) return -1;
    ++number_of_stops;
    --current_index;
  }
  return number_of_stops;
}

int main(int argc, char const *argv[]) {
  int d, r, n;
  std::cin >> d >> r >> n;
  std::vector<int> stops = {0};
  for (auto i = 0; i < n; ++i) {
    int temp;
    std::cin >> temp;
    stops.push_back(temp);
  }
  stops.push_back(d);
  std::cout << number_of_stops(r, stops) << std::endl;
  return 0;
}
