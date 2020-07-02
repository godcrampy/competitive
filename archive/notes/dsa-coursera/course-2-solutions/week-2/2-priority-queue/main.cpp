#include <iostream>
#include <vector>

using namespace std;

typedef struct thread {
  long index;
  long long time_when_free = 0;
} thread;

bool operator<(thread a, thread b) {
  if (a.time_when_free == b.time_when_free) {
    return a.index < b.index;
  }
  return a.time_when_free < b.time_when_free;
}

void heapify(long i, vector<thread> &threads);

int main(int argc, char const *argv[]) {
  long n, m;
  cin >> n >> m;
  vector<long long> jobs(m, 0);
  vector<thread> threads(n);
  for (long i = 0; i < m; ++i) {
    cin >> jobs[i];
  }
  for (long i = 0; i < n; ++i) {
    thread temp;
    temp.index = i;
    threads[i] = temp;
  }
  for (auto job : jobs) {
    // extract min
    thread temp = threads[0];
    // print min
    cout << temp.index << " " << temp.time_when_free << endl;
    // fill min
    temp.time_when_free += job;
    // push min
    threads[0] = temp;
    // heapify
    heapify(0, threads);
  }
  return 0;
}

void heapify(long i, vector<thread> &threads) {
  long n = threads.size();
  if (i >= n || i < 0) return;
  bool is_left_child = 2 * i + 1 < n;
  bool is_right_child = 2 * i + 2 < n;
  long swp_index = i;
  thread min = threads[i];
  if (is_left_child && threads[2 * i + 1] < min) {
    min = threads[2 * i + 1];
    swp_index = 2 * i + 1;
  }
  if (is_right_child && threads[2 * i + 2] < min) {
    min = threads[2 * i + 2];
    swp_index = 2 * i + 2;
  }
  if (swp_index != i) {
    swap(threads[i], threads[swp_index]);
    heapify(swp_index, threads);
  }
}
