#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int randomNumber(int l, int r) {
  // * Returns a random integer from [l, r]
  return l + (std::rand() % (r - l + 1));
}

template <typename T>
void printVector(const vector<T>& v, string msg) {
  cout << msg;
  for (auto n : v) {
    cout << n << " ";
  }
  cout << endl;
}

// ? Given arrival and departure times of all trains that reach a railway
// station. Your task is to find the minimum number of platforms required for
// the railway station so that no train waits.

// ? Note: Consider that all the trains arrive on the same day and leave on the
// same day. Also, arrival and departure times will not be same for a train, but
// we can have arrival time of one train equal to departure of the other. In
// such cases, we need different platforms, i.e at any given instance of time,
// same platform can not be used for both departure of a train and arrival of
// another.

int setApproach(vector<int> arrival, vector<int> departure) {
  // * T:O(nlogn) S:O(n)
  int n = arrival.size();

  vector<pair<int, int>> times(n);

  for (int i = 0; i < n; ++i) {
    times[i] = {arrival[i], departure[i]};
  }

  sort(times.begin(), times.end());

  multiset<int> deps;
  int maxPlatforms = 0;

  for (int i = 0; i < n; ++i) {
    // insert current train
    deps.insert(times[i].second);
    // remove previous departures smaller than current time
    deps.erase(deps.begin(), deps.lower_bound(times[i].first));
    int s = deps.size();
    maxPlatforms = max(maxPlatforms, s);
  }

  return maxPlatforms;
}

int dualSortApproach(vector<int> arrival, vector<int> departure) {
  // * T:O(nlogn) S:O(1)
  if (arrival.size() == 1) {
    return 1;
  }
  int n = arrival.size();
  sort(arrival.begin(), arrival.end());
  sort(departure.begin(), departure.end());

  int res = 1, platforms = 1;
  int i = 1, j = 0;

  while (i < n && j < n) {
    if (arrival[i] <= departure[j]) {
      ++platforms;
      ++i;
    } else if (arrival[i] > departure[j]) {
      --platforms;
      ++j;
    }

    res = max(res, platforms);
  }

  return res;
}

int vectorApproach(vector<int> arrival, vector<int> departure) {
  // * T:O(n) S:O(1)
  vector<int> platform(2361, 0);  // minutes in a day, basically max element
                                  // value in arrival, departure
  int n = arrival.size();
  for (int i = 0; i < n; ++i) {
    platform[arrival[i]]++;
    platform[departure[i] + 1]--;
  }

  for (int i = 1; i < 2361; ++i) {
    platform[i] += platform[i - 1];
  }

  return *max_element(platform.begin(), platform.end());
}

void smokeTest() {
  for (int i = 0; i < 1000; ++i) {
    cout << "Test: " << i + 1 << endl;
    int n = randomNumber(1, 1000);
    vector<int> a(n), d(n);
    for (int j = 0; j < n; ++j) {
      a[j] = randomNumber(1, 1000);
    }
    for (int j = 0; j < n; ++j) {
      d[j] = a[j] + randomNumber(1, 1000);
    }
    int x = setApproach(a, d);
    int y = vectorApproach(a, d);
    if (x != y) {
      cout << "Test Failed" << endl;
      vector<int> ans = {x, y};
      printVector(a, "a: ");
      printVector(d, "d: ");
      printVector(ans, "x, y: ");
      return;
    }
  }
  cout << "Test Passed" << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(time(0));

  smokeTest();
  return 0;
}
