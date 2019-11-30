#include <iostream>

using namespace std;

const int set_size = 10;

int find(int arr[set_size], int x);
void make_union(int arr[set_size], int a, int b);
bool same_set(int arr[set_size], int a, int b);

int main(int argc, char const *argv[]) {
  int arr[set_size];
  for (int i = 0; i < set_size; ++i) {
    arr[i] = i;
  }
  make_union(arr, 1, 2);
  make_union(arr, 5, 2);
  make_union(arr, 6, 5);

  make_union(arr, 3, 9);
  make_union(arr, 8, 4);
  make_union(arr, 3, 4);

  cout << find(arr, 3) << endl;

  return 0;
}

int find(int arr[set_size], int x) {
  if (arr[x] == x) {
    return x;
  }
  return find(arr, arr[x]);
}

void make_union(int arr[set_size], int a, int b) {
  int a_parent = find(arr, a);
  int b_parent = find(arr, b);
  int max_ab = max(a_parent, b_parent);
  arr[a_parent] = max_ab;
  arr[b_parent] = max_ab;
}

bool same_set(int arr[set_size], int a, int b) {
  return find(arr, a) == find(arr, b);
}
