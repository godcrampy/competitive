#include <iostream>
#include "util.h"

using namespace std;

int main(int argc, char const *argv[]) {
  int numberOfPackets;
  while (true) {
    cin >> numberOfPackets;
    int candies[numberOfPackets];
    for (int i = 0; i < numberOfPackets; i++)
      cin >> candies[i];
    int sum = sumOfArray(candies, numberOfPackets);
    if (sum % numberOfPackets != 0) {
      cout << -1 << endl;
      break;
    }
    int average = sum / numberOfPackets;
    int change = 0;
    for (int i = 0; i < numberOfPackets; i++)
      change += abs(average - candies[i]);
    cout << change / 2 << endl;
  }
  return 0;
}
