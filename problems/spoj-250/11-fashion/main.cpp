#include <iostream>
#include <algorithm>

int get_hotness(int men_rating[], int women_rating[], int length)
{
  int sum = 0; // sum of optimum hotness
  std::sort(men_rating, men_rating + length);
  std::sort(women_rating, women_rating + length);
  for (int i = 0; i < length; i++)
    sum += men_rating[i] * women_rating[i];
  return sum;
}

using namespace std;

int main(int argc, char const *argv[])
{
  int t, number_of_contestants;
  cin >> t;
  for (int _ = 0; _ < t; _++)
  {
    cin >> number_of_contestants;
    int men_ratings[number_of_contestants], women_rating[number_of_contestants];
    for (int i = 0; i < number_of_contestants; i++)
      cin >> men_ratings[i];
    for (int i = 0; i < number_of_contestants; i++)
      cin >> women_rating[i];
    cout << get_hotness(men_ratings, women_rating, number_of_contestants) << endl;
  }
  return 0;
}
