#include <string>
using namespace std;

string toLowerCase(string str) {
  for (char &c : str) {
    if (c >= 'A' && c <= 'Z') {
      c += 'a' - 'A';
    }
  }
  return str;
}