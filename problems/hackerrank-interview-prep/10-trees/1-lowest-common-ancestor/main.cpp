#include <bits/stdc++.h>

using namespace std;

/*The tree node has data, left child and right child
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

Node* lca(Node* root, int v1, int v2) {
  if (root == NULL) {
    return NULL;
  }

  if (root->data == v1 || root->data == v2) {
    return root;
  }

  Node* left = lca(root->left, v1, v2);
  Node* right = lca(root->right, v1, v2);

  if (left != NULL && right != NULL) {
    return root;
  }

  return left != NULL ? left : right;
}
