#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void heapify(long i, vector<long> &array, vector<pair<long, long>> &list);
void _swap(long &a, long &b);

int main(int argc, char const *argv[]) {
  long n;
  cin >> n;
  vector<long> array(n, 0);
  vector<pair<long, long>> list;
  for (long i = 0; i < n; ++i) {
    cin >> array[i];
  }
  for (long i = n / 2; i >= 0; --i) {
    heapify(i, array, list);
  }
  cout << list.size() << endl;
  for (auto pair : list) {
    cout << pair.first << " " << pair.second << endl;
  }
  return 0;
}

void _swap(long &a, long &b) {
  long temp = a;
  a = b;
  b = temp;
}

void heapify(long i, vector<long> &array, vector<pair<long, long>> &list) {
  int n = array.size();
  if (i >= n || i < 0) return;
  bool is_left_child = 2 * i + 1 < n;
  bool is_right_child = 2 * i + 2 < n;
  unsigned long swp_index = i;
  long min = array[i];
  if (is_left_child && array[2 * i + 1] < min) {
    min = array[2 * i + 1];
    swp_index = 2 * i + 1;
  }
  if (is_right_child && array[2 * i + 2] < min) {
    min = array[2 * i + 2];
    swp_index = 2 * i + 2;
  }
  if (swp_index != i) {
    list.push_back({i, swp_index});
    swap(array[i], array[swp_index]);
    heapify(swp_index, array, list);
  }
}
