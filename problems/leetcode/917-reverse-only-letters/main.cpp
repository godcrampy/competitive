#include <string>

using namespace std;

bool is_letter(char a) {
  return (a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z');
}
string reverseOnlyLetters(string S) {
  if (S.length() == 0) return S;

  int l = 0;
  int r = S.length();

  while (l <= r) {
    if (!(is_letter(S[l]))) {
      ++l;
      continue;
    }
    if (!(is_letter(S[r]))) {
      --r;
      continue;
    }

    swap(S[l], S[r]);
    ++l;
    --r;
  }

  return S;
}