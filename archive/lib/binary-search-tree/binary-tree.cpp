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

void delete_node(node* root, int data);
node* search_node(node* root, int data);
node* search_parent_node(node* root, int data);
int _number_of_children(node* node);
node* _smallest_child(node* node);
void delete_node(node* node, int data);
int distance_from_root(node* root, int data);
bool are_siblings(node* root, int a, int b);

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

  cout << are_siblings(root, 1, 8) << " " << are_siblings(root, 3, 8) << endl;
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

node* search_node(node* root, int data) {
  if (root == NULL) {
    return NULL;
  }
  if (data > root->data) {
    return search_node(root->right, data);
  }
  if (data < root->data) {
    return search_node(root->left, data);
  }
  // * root->data == data
  return root;
}

node* search_parent_node(node* root, int data) {
  if (root == NULL) {
    return NULL;
  }
  if (root->left->data == data || root->right->data == data) {
    return root;
  }
  if (data > root->data) {
    return search_parent_node(root->right, data);
  }
  // * data < root->data
  return search_parent_node(root->left, data);
}

int _number_of_children(node* node) {
  int count = 0;
  if (node->left != NULL) {
    ++count;
  }
  if (node->right != NULL) {
    ++count;
  }
  return count;
}

node* _smallest_child(node* node) {
  if (node->left == NULL) {
    return node;
  }
  return _smallest_child(node->left);
}

void delete_node(node* root, int data) {
  node* del = search_node(root, data);
  node* parent = search_parent_node(root, data);
  bool is_left_child = parent->left->data == data ? true : false;
  int count = _number_of_children(del);
  switch (count) {
    case 0:
      if (is_left_child) {
        parent->left = NULL;
      } else {
        parent->right = NULL;
      }
      break;
    case 1:
      if (is_left_child) {
        if (del->left != NULL) {
          parent->left = del->left;
        } else {
          parent->left = del->right;
        }
      } else {
        if (del->right != NULL) {
          parent->left = del->left;
        } else {
          parent->right = del->right;
        }
      }
      break;
    default:
      // * 2 children
      node* hier = _smallest_child(del->right);
      delete_node(root, hier->data);
      del->data = hier->data;
  }
}

int distance_from_root(node* root, int data) {
  if (data > root->data) {
    return 1 + distance_from_root(root->right, data);
  }
  if (data < root->data) {
    return 1 + distance_from_root(root->left, data);
  }
  return 0;
}

bool are_siblings(node* root, int a, int b) {
  if (distance_from_root(root, a) == distance_from_root(root, b) &&
      search_parent_node(root, a) == search_parent_node(root, b)) {
    return true;
  }
  return false;
}
