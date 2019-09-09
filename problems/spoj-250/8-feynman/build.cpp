#include <iostream>

using namespace std;

int numberOfPositions(int largeSize, int smallSize)
{
  return (largeSize - smallSize + 1) * (largeSize - smallSize + 1);
}

int totalPositions(int sizeOfSquare)
{
  int final{};
  for (int i = 1; i <= sizeOfSquare; i++)
    final += numberOfPositions(sizeOfSquare, i);
  return final;
}

int main(int argc, char const *argv[])
{
  int number{};
  while (true)
  {
    cin >> number;
    if (number == 0)
      break;
    cout << totalPositions(number) << endl;
  }
  return 0;
}
