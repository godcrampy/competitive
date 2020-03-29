#include <iostream>
#include <map>
#include <utility>
#include <vector>

typedef std::map<std::string, std::pair<int, int>> database;

int main(int argc, char const *argv[]) {
  int t;
  std::cin >> t;
  std::getchar();
  for (auto _ = 0; _ < t; ++_) {
    int count;
    database db;
    std::cin >> count;
    std::getchar();
    for (auto i = 0; i < count; ++i) {
      std::string string;
      int value;
      std::getline(std::cin, string, ' ');
      std::cin >> value;
      std::getchar();
      if (db.count(string)) {
        // string exists
        if (value == 0)
          ++db[string].first;
        else
          ++db[string].second;
      } else {
        if (value == 0)
          db.insert({string, {1, 0}});
        else
          db.insert({string, {0, 1}});
      }
    }
    long sum = 0;
    for (auto const &item : db) {
      auto a = item.second;
      sum += std::max(a.first, a.second);
    }
    std::cout << sum << std::endl;
  }
  return 0;
}
