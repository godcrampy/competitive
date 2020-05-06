#include <iostream>
#include <random>
#include <vector>

using namespace std;

// This function is given
size_t getRandom(size_t floor, size_t ceiling) {
  static random_device rdev;
  static default_random_engine generator(rdev());
  static uniform_real_distribution<double> distribution(0.0, 1.0);
  double value = distribution(generator);
  return static_cast<size_t>(value * (ceiling - floor + 1)) + floor;
}

void shuffle(vector<int>& theVector) {
  // shuffle the input in place
  int length = theVector.size();
  for (int i = 0; i < length - 1; ++i) {
    int j = getRandom(i + 1, length - 1);
    swap(theVector[i], theVector[j]);
  }
}