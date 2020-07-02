#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int t;
  std::cin >> t;
  long number_of_stamps, number_of_friends;
  for (int _ = 0; _ < t; _++) {
    std::cin >> number_of_stamps >> number_of_friends;
    std::vector<long> stamps;
    for (auto i = 0; i < number_of_friends; ++i) {
      long temp;
      std::cin >> temp;
      stamps.push_back(temp);
    }
    std::sort(stamps.begin(), stamps.end(), std::greater<long>());

    long collection = 0;
    bool flag = false;
    int count = 0;
    for (long number : stamps) {
      collection += number;
      ++count;
      if (collection >= number_of_stamps) {
        flag = true;
        break;
      }
    }
    std::cout << "Scenario #" << _ + 1 << ":" << std::endl;
    if (flag)
      std::cout << count << "\n" << std::endl;
    else
      std::cout << "impossible"
                << "\n"
                << std::endl;
  }
  return 0;
}
