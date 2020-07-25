/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL

Node* bToDLL(Node* root) {
  if (root == NULL) {
    return root;
  }

  Node* left = bToDLL(root->left);
  Node* right = bToDLL(root->right);

  Node* res = root;
  if (left != NULL) {
    res = left;
    while (left->right != NULL) {
      left = left->right;
    }
    left->right = root;
    root->left = left;
  }

  root->right = right;
  if (right != NULL) {
    right->left = root;
  }

  return res;
}
