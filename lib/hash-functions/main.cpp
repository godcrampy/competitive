#include <iostream>
#include <string>

using namespace std;

int hash_numbers(long number) {
  const long p = 39916801;   // large prime
  const long a = 34, b = 7;  // a, b < p
  const long m = 1000;       // cardinality
  return (a * number + b) % p % m;
}

int hash_string(string message) {
  const int x = 31;    // prime number
  const int p = 1000;  // cardinality
  int hash = 0;
  for (long i = message.length() - 1; i >= 0; --i) {
    hash += (hash * x + message[i]) % p;
  }
  return hash;
}

int main(int argc, char const *argv[]) {
  cout << hash_string("Hello World") << endl;
  cout << hash_string("Hello Worlf") << endl;
  return 0;
}
