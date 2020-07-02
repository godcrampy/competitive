#include <iostream>
#include <stack>

using namespace std;

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
  Node(int data = 0) : data(data), left(nullptr), right(nullptr) {}
} Node;

class BST {
 private:
  Node *root;

 public:
  BST() : root(nullptr) {}
  void insert(int data);
  void inorder_traversal();
  void preorder_traversal();
  void postorder_traversal();
};

void BST::insert(int data) {
  Node *node = new Node(data);
  if (this->root == nullptr) {
    this->root = node;
    return;
  }
  Node *iterator = this->root;
  while (true) {
    if (iterator->data == data)
      return;
    else if (iterator->data > data) {
      if (iterator->left == nullptr) {
        iterator->left = node;
        break;
      }
      iterator = iterator->left;
    } else {
      if (iterator->right == nullptr) {
        iterator->right = node;
        break;
      }
      iterator = iterator->right;
    }
  }
}

void BST::inorder_traversal() {
  if (this->root == nullptr) return;
  stack<Node *> stack;
  Node *iterator = this->root;
  while (true) {
    if (iterator != nullptr) {
      stack.push(iterator);
      iterator = iterator->left;
    } else {
      if (stack.empty()) break;
      iterator = stack.top();
      stack.pop();
      cout << iterator->data << " ";
      iterator = iterator->right;
    }
  }
  cout << endl;
}

void BST::preorder_traversal() {
  stack<Node *> stack;
  stack.push(this->root);
  while (!stack.empty()) {
    auto temp = stack.top();
    cout << temp->data << " ";
    stack.pop();
    if (temp->right != nullptr) stack.push(temp->right);
    if (temp->left != nullptr) stack.push(temp->left);
  }
  cout << endl;
}

void BST::postorder_traversal() {
  stack<Node *> stack1, stack2;
  stack1.push(this->root);
  while (!stack1.empty()) {
    auto temp = stack1.top();
    stack1.pop();
    stack2.push(temp);
    if (temp->left != nullptr) stack1.push(temp->left);
    if (temp->right != nullptr) stack1.push(temp->right);
  }
  while (!stack2.empty()) {
    cout << stack2.top()->data << " ";
    stack2.pop();
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  BST tree;
  tree.insert(4);
  tree.insert(2);
  tree.insert(7);
  tree.insert(1);
  tree.insert(3);
  tree.insert(5);
  tree.insert(8);
  tree.insert(6);
  tree.inorder_traversal();
  tree.preorder_traversal();
  tree.postorder_traversal();
  return 0;
}
