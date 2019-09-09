#include <iostream>
#include "util.h"

using namespace std;

int main(int argc, char const *argv[])
{
  int men_rating[3] = {1, 2, 3}, women_rating[3] = {3, 2, 1};
  cout << get_hotness(men_rating, women_rating, 3) << endl;
  return 0;
}
