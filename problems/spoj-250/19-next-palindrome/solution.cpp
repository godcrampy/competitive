// Aemie Solution
#include <iostream>
#include <string>

using namespace std;

string reverseString(string stringName)
{
  int size = stringName.length();
  for (int i = 0; i < size / 2; i++)
  {
    swap(stringName[i], stringName[size - i - 1]);
  }
  return stringName;
}

int allElementsNine(string input, int size)
{
  for (int i = 0; i < size; i++)
  {
    if (input[i] != '9')
      return 0;
  }
  return 1;
}

string nextPalindromeOdd(string input, int size)
{
  string copy = input, duplicate;
  duplicate = reverseString(input);
  int center = size / 2;
  for (int i = center + 1; i < size; i++)
    copy[i] = duplicate[i];
  if (copy <= input && allElementsNine(copy, size) == 0)
  {
    int count = 0;
    while (copy[center - count] == '9' && (size / 2 - count) > 0)
    {
      copy[center - count] = '0';
      if (count != 0)
        copy[center + count] = '0';
      count++;
    }
    if (copy[center - count] < '9')
    {
      copy[center - count] = (copy[center - count] - '0') + 1 + '0';
      if (count != 0)
        copy[center + count] = (copy[center + count] - '0') + 1 + '0';
    }
  }
  if (copy <= input && allElementsNine(copy, size) == 1)
  {
    for (int i = 1; i < size; i++)
      copy[i] = '0';
    copy[0] = '1';
    copy += "1";
  }
  return copy;
}

string nextPalindromeEven(string input, int size)
{

  string copy = input, duplicate;
  duplicate = reverseString(input);
  for (int i = size / 2; i < size; i++)
    copy[i] = duplicate[i];
  if (copy <= input && allElementsNine(copy, size) == 0)
  {
    int count = 1;
    while (copy[size / 2 - count] == '9' && (size / 2 - count) > 0)
    {
      copy[size / 2 - count] = '0';
      copy[size / 2 + count - 1] = '0';
      count++;
    }
    if (copy[size / 2 - count] < '9')
    {
      copy[size / 2 - count] = (copy[size / 2 - count] - '0') + 1 + '0';
      copy[size / 2 + count - 1] = (copy[size / 2 + count - 1] - '0') + 1 + '0';
    }
  }

  if (copy <= input && allElementsNine(copy, size) == 1)
  {
    for (int i = 1; i < size; i++)
      copy[i] = '0';
    copy[0] = '1';
    copy += "1";
  }
  return copy;
}

string nextPalindromeBasic(string input, int size)
{
  string copy = input;
  if (size == 1)
    if (copy == "9")
      copy = "11";
    else
      copy[0] = (input[0] - '0') + 1 + '0';
  else
  {
    copy[1] = copy[0];
    if (copy <= input)
    {
      copy[1] = (copy[1] - '0') + 1 + '0';
      copy[0] = (copy[0] - '0') + 1 + '0';
    }
  }
  if (input == "99")
    copy = "101";
  return copy;
}

int main()
{
  int test;
  string digit, nextPalindrome;
  cin >> test;
  cin.ignore(256, '\n');
  for (int _ = 0; _ < test; _++)
  {
    getline(cin, digit);
    digit.erase(0, min(digit.find_first_not_of('0'), digit.size() - 1));
    int size = digit.length();

    if (size == 1 || size == 2)
      nextPalindrome = nextPalindromeBasic(digit, size);

    else if (size % 2 == 0)
      nextPalindrome = nextPalindromeEven(digit, size);

    else if (size % 2 != 0)
      nextPalindrome = nextPalindromeOdd(digit, size);

    cout << nextPalindrome << endl;
  }
  return 0;
}