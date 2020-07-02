#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long long p = 10e9 + 7;  // cardinality

long long hash_string(string message, long l, long r) {
  long long hash = 0;
  for (long i = l; i <= r; ++i) {
    hash += ((long long)message[i]) % p;
  }
  return hash;
}

int main(int argc, char const *argv[]) {
  string pattern, text;
  cin >> pattern >> text;
  long text_length = text.length();
  long pattern_length = pattern.length();
  long long hash_pattern = hash_string(pattern, 0, pattern.length() - 1);

  vector<long long> precomputed_hashes(text_length - pattern_length + 1, 0);

  precomputed_hashes[text_length - pattern_length] = hash_string(text, text_length - pattern_length, text_length - 1);

  for (long i = text_length - pattern_length - 1; i >= 0; --i) {
    precomputed_hashes[i] = (precomputed_hashes[i + 1] + text[i] - text[i + pattern_length]) % p;
  }

  // cout << hash_pattern << endl;

  for (long i = 0; i < text_length - pattern_length + 1; ++i) {
    if (hash_pattern == precomputed_hashes[i]) {
      bool mathces = true;
      for (long j = 0; j < pattern_length; ++j) {
        if (pattern[j] != text[i + j]) {
          mathces = false;
          break;
        }
      }
      if (mathces) {
        cout << i << " ";
      }
    }
  }
  cout << endl;
  return 0;
}
