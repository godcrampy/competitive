
#include <iostream>

using namespace std;

void processEmail(string &email) {
  int i = 0;
  while (i < email.length()) {
    char c = email[i];
    if (c == '@') return;
    if (c == '.') email.erase(i, 1);
    if (c == '+') {
      while (email[i] != '@') {
        email.erase(i, 1);
      }
      break;
    }
    ++i;
  }
}