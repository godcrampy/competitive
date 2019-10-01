#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void updateBIT(int BIT[], long long int index, long long int size)
{
  while (index <= size)
  {
    BIT[index] += 1;
    index += (index) & (-index);
  }
}

int totalSum(int BIT[], long long int index)
{
  long long int sum = 0;
  while (index > 0)
  {
    sum += BIT[index];
    index -= (index) & (-index);
  }
  return sum;
}

vector<int> convert(vector<int> array, long long int size)
{
  vector<int> copy = array;
  sort(copy.begin(), copy.end());
  for (long long int i = 0; i < size; i++)
    array[i] = lower_bound(copy.begin(), copy.end(), array[i]) - copy.begin() + 1;

  return array;
}

long long int totalInversions(vector<int> array, long long int size)
{
  array = convert(array, size);
  int BIT[size + 1];
  for (int i = 1; i < size; ++i)
    BIT[i] = 0;
  long long int inverseCount = 0;
  for (int i = size - 1; i >= 0; --i)
  {
    inverseCount += totalSum(BIT, array[i] - 1);
    updateBIT(BIT, array[i], size);
  }
  return inverseCount;
}

int main()
{
  /* USE OF BIT : BINARY INDEXED TREE*/
  int test;
  cin >> test;
  for (int _ = 0; _ < test; _++)
  {
    cout << endl;
    long long int total;
    cin >> total;
    vector<int> storeNum;
    for (long long int _ = 0; _ < total; _++)
    {
      long long int number;
      cin >> number;
      storeNum.push_back(number);
    }

    long long int count = totalInversions(storeNum, total);
    cout << count << endl;
  }
  return 0;
}