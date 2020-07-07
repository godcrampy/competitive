#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {
    val = 0;
    children = {NULL, NULL};
  };

  Node(int val) : val(val), children({NULL, NULL}) {}
};

void insert(Node* trie, int n, int index) {
  if (index < 0) {
    return;
  }

  int x = (n >> index) & 1;

  if (trie->children[x] == NULL) {
    trie->children[x] = new Node(x);
  }

  insert(trie->children[x], n, index - 1);
}

int findMax(Node* trie, int n, int index, int p) {
  if (index < 0) {
    return p;
  }

  // find if opposite is there
  int x = (n >> index) & 1;
  x ^= 1;

  if (trie->children[x] != NULL) {
    p |= (x << index);
    return findMax(trie->children[x], n, index - 1, p);
  }

  x ^= 1;
  p |= (x << index);
  return findMax(trie->children[x], n, index - 1, p);
}

// Complete the maxXor function below.
vector<int> maxXor(vector<int> arr, vector<int> queries) {
  Node* trie = new Node();
  for (int n : arr) {
    insert(trie, n, 31);
  }

  vector<int> res;

  for (int n : queries) {
    int p = 0;
    p = findMax(trie, n, 31, p);
    res.push_back(p ^ n);
  }

  return res;
}
