#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {
  long n;
  cin >> n;
  unordered_map<long long, string> phone_book;
  for (long i = 0; i < n; ++i) {
    string code;
    cin >> code;
    if (code == "add") {
      string number, name;
      cin >> number >> name;
      if (phone_book.find(stoll(number)) == phone_book.end()) {
        phone_book.insert({stoll(number), name});
      } else {
        phone_book[stoll(number)] = name;
      }
    } else if (code == "find") {
      string number;
      cin >> number;
      if (phone_book.find(stoll(number)) == phone_book.end()) {
        cout << "not found" << endl;
      } else {
        cout << phone_book[stoll(number)] << endl;
      }
    } else {
      string number;
      cin >> number;
      phone_book.erase(stoll(number));
    }
  }
  return 0;
}
