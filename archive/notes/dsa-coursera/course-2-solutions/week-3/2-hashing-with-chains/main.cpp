#include <iostream>
#include <string>
#include <vector>

using namespace std;

long hash_func(string string, long m);

void add(vector<vector<string>> &table, string string, long hash);
void del(vector<vector<string>> &table, string string, long hash);
void find(vector<vector<string>> &table, string string, long hash);

int main(int argc, char const *argv[]) {
  /* code */
  long n, m;
  cin >> m >> n;
  vector<vector<string>> table(m);
  for (long i = 0; i < n; ++i) {
    string query, input;
    cin >> query >> input;
    if (query == "add") {
      add(table, input, hash_func(input, m));
    } else if (query == "del") {
      del(table, input, hash_func(input, m));
    } else if (query == "find") {
      find(table, input, hash_func(input, m));
    } else {
      for (auto itr = table[stoll(input)].rbegin();
           itr != table[stoll(input)].rend(); ++itr) {
        cout << *itr << " ";
      }
      cout << endl;
    }
  }
  return 0;
}

long hash_func(string string, long m) {
  const int x = 263;
  const long p = 1000000007;
  long hash = 0;
  for (long i = 0; i < string.length(); ++i) {
    long exp = 1;
    for (long j = 0; j < i; ++j) {
      exp *= x;
      exp %= p;
    }
    hash += string[i] * exp;
    hash %= p;
  }
  hash %= m;
  return hash;
}

void add(vector<vector<string>> &table, string string, long hash) {
  for (auto value : table[hash]) {
    if (value == string) {
      return;
    }
  }
  table[hash].push_back(string);
}

void del(vector<vector<string>> &table, string string, long hash) {
  for (auto itr = table[hash].begin(); itr != table[hash].end(); ++itr) {
    if (*itr == string) {
      table[hash].erase(itr);
      return;
    }
  }
}

void find(vector<vector<string>> &table, string string, long hash) {
  for (auto itr = table[hash].begin(); itr != table[hash].end(); ++itr) {
    if (*itr == string) {
      cout << "yes" << endl;
      return;
    }
  }
  cout << "no" << endl;
}
