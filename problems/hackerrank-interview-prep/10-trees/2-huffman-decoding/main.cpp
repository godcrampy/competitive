#include <bits/stdc++.h>
using namespace std;

typedef struct node {
  int freq;
  char data;
  node* left;
  node* right;
} node;

void decode_huff(node* root, string s) {
  string res = "";
  int i = 0;
  node* itr = root;
  while (i < s.length()) {
    // decode letter
    itr = root;
    while (itr->data == 0) {
      if (s[i] == '1') {
        itr = itr->right;
      } else {
        itr = itr->left;
      }
      ++i;
    }
    // add to res
    res += itr->data;
  }
  cout << res << endl;
}
