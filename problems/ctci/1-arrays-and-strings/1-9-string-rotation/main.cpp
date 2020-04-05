#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string &a, string &b) {
  // is b substring of a
  return a.find(b) != a.npos;
}

bool isRotation(string &a, string &b) {
  // * Time: O(|a| + |b|) if isSubstring is KMP
  // * Space: O(|a|)
  string c = a + a;
  return isSubstring(c, b);
}

int main(int argc, char const *argv[]) {
  string a = "waterbottler";
  string b = "terbottlerwat";
  cout << isRotation(a, b) << endl;
  return 0;
}
