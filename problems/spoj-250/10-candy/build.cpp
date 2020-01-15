#include <iostream>

using namespace std;

int sumOfArray(int array[], int length) {
  int sum = 0;
  for (int i = 0; i < length; i++)
    sum += array[i];
  return sum;
}

int main(int argc, char const *argv[]) {
  int numberOfPackets;
  while (true) {
    cin >> numberOfPackets;
    if (numberOfPackets == -1)
      break;
    int candies[numberOfPackets];
    for (int i = 0; i < numberOfPackets; i++)
      cin >> candies[i];
    int sum = sumOfArray(candies, numberOfPackets);
    if (sum % numberOfPackets != 0) {
      cout << -1 << endl;
    } else {
      int average = sum / numberOfPackets;
      int change = 0;
      for (int i = 0; i < numberOfPackets; i++)
        change += abs(average - candies[i]);
      cout << change / 2 << endl;
    }
  }
  return 0;
}
