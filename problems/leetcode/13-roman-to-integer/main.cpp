#include <string>
using namespace std;

int romanToInt(string s) {
  int i = 0;
  int val = 0;

  while (i < s.length()) {
    if (i + 1 < s.length()) {
      string two = s.substr(i, 2);
      if (two == "CM") {
        val += 900;
        i += 2;
        continue;
      } else if (two == "CD") {
        val += 400;
        i += 2;
        continue;
      } else if (two == "XC") {
        val += 90;
        i += 2;
        continue;
      } else if (two == "XL") {
        val += 40;
        i += 2;
        continue;
      } else if (two == "IX") {
        val += 9;
        i += 2;
        continue;
      } else if (two == "IV") {
        val += 4;
        i += 2;
        continue;
      }
    }

    string one = s.substr(i, 1);
    if (one == "M") {
      val += 1000;
    } else if (one == "D") {
      val += 500;
    } else if (one == "C") {
      val += 100;
    } else if (one == "L") {
      val += 50;
    } else if (one == "X") {
      val += 10;
    } else if (one == "V") {
      val += 5;
    } else {
      val += 1;
    }
    ++i;
  }
  return val;
}