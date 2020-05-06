#include <iostream>
#include <vector>

using namespace std;

// ! IMP

int productOfThree(const vector<int>& v) {
  return v[0] * v[1] * v[2];
}

int highestProductOf3(const vector<int>& vectorOfInts) {
  // calculate the highest product of three numbers
  int length = vectorOfInts.size();
  if (length < 3) {
    throw "";
  }

  int highest = max(vectorOfInts[0], vectorOfInts[1]);
  int lowest = min(vectorOfInts[0], vectorOfInts[1]);

  int highestProductOf2 = vectorOfInts[0] * vectorOfInts[1];
  int lowestProductOf2 = vectorOfInts[0] * vectorOfInts[1];

  int highestProductOf3 = vectorOfInts[0] * vectorOfInts[1] * vectorOfInts[2];

  for (int i = 2; i < length; ++i) {
    int current = vectorOfInts[i];

    highestProductOf3 = max(max(
                                highestProductOf3,
                                current * highestProductOf2),
                            current * lowestProductOf2);

    highestProductOf2 = max(max(
                                highestProductOf2,
                                current * highest),
                            current * lowest);

    lowestProductOf2 = min(min(
                               lowestProductOf2,
                               current * highest),
                           current * lowest);

    highest = max(current, highest);
    lowest = min(lowest, current);
  }

  return highestProductOf3;
}
