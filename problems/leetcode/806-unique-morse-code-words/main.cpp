#include <set>
#include <string>
#include <vector>

using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
  vector<string> key = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                        "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                        "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                        "...-", ".--",  "-..-", "-.--", "--.."};
  set<string> codes;
  for (string word : words) {
    string temp = "";
    for (char c : word) {
      temp += key[c - 'a'];
    }
    codes.insert(temp);
  }
  return codes.size();
}