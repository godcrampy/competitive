#include <iostream>
#include <stack>

using namespace std;

typedef struct node {
  int data;
  struct node* left = NULL;
  struct node* right = NULL;
} node;

void insert(node* root, int data);
void inorder_recursive(node* root);
void preorder_recursive(node* root);
void postorder_recursive(node* root);

void inorder_iterative(node* root);
void preorder_iterative(node* root);
void postorder_iterative(node* root);

int main(int argc, char const* argv[]) {
  node* root = new node;
  root->data = 5;
  insert(root, 3);
  insert(root, 8);
  insert(root, 1);
  insert(root, 4);
  insert(root, 6);
  insert(root, 9);
  insert(root, 0);
  insert(root, 2);
  insert(root, 7);

  inorder_recursive(root);
  cout << endl;
  inorder_iterative(root);

  preorder_recursive(root);
  cout << endl;
  preorder_iterative(root);

  postorder_recursive(root);
  cout << endl;
  postorder_iterative(root);
  return 0;
}

void insert(node* root, int data) {
  node* node = new struct node;
  node->data = data;
  if (root->data < node->data) {
    if (root->right == NULL) {
      root->right = node;
    } else {
      insert(root->right, data);
    }
  } else if (root->data > node->data) {
    if (root->left == NULL) {
      root->left = node;
    } else {
      insert(root->left, data);
    }
  }
}

void inorder_recursive(node* root) {
  if (root == NULL) {
    return;
  }
  inorder_recursive(root->left);
  cout << root->data << " ";
  inorder_recursive(root->right);
}

void preorder_recursive(node* root) {
  if (root == NULL) {
    return;
  }
  cout << root->data << " ";
  preorder_recursive(root->left);
  preorder_recursive(root->right);
}

void postorder_recursive(node* root) {
  if (root == NULL) {
    return;
  }
  postorder_recursive(root->left);
  postorder_recursive(root->right);
  cout << root->data << " ";
}

void inorder_iterative(node* root) {
  stack<node*> stack;
  node* iterator = root;
  while (iterator != NULL || !stack.empty()) {
    if (iterator != NULL) {
      stack.push(iterator);
      iterator = iterator->left;
    } else {
      iterator = stack.top();
      stack.pop();
      cout << iterator->data << " ";
      iterator = iterator->right;
    }
  }
  cout << endl;
}

void preorder_iterative(node* root) {
  stack<node*> stack;
  stack.push(root);
  while (!stack.empty()) {
    node* top = stack.top();
    stack.pop();
    cout << top->data << " ";
    if (top->right != NULL) {
      stack.push(top->right);
    }
    if (top->left != NULL) {
      stack.push(top->left);
    }
  }
  cout << endl;
}

void postorder_iterative(node* root) {
  stack<node*> stack_1, stack_2;
  stack_1.push(root);
  while (!stack_1.empty()) {
    node* top = stack_1.top();
    stack_1.pop();
    stack_2.push(top);
    if (top->left != NULL) {
      stack_1.push(top->left);
    }
    if (top->right != NULL) {
      stack_1.push(top->right);
    }
  }
  while (!stack_2.empty()) {
    cout << stack_2.top()->data << " ";
    stack_2.pop();
  }
  cout << endl;
}
