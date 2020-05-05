#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool canTwoMoviesFillFlight(const vector<int>& movieLengths, int flightLength) {
  // determine if two movies add up to the flight length
  unordered_set<int> s;

  for (const int n : movieLengths) {
    int complement = flightLength - n;
    if (s.find(complement) != s.end()) {
      // match
      return true;
    }
    s.insert(n);
  }

  return false;
}
