
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/*this  function serializes
the binary tree and stores
it in the vector A*/
void serialize(Node *root, vector<int> &A) {
  if (root == NULL) {
    A.push_back(0);
    return;
  };
  A.push_back(root->data);

  serialize(root->left, A);
  serialize(root->right, A);
}

Node *deSerRec(deque<int> &q) {
  if (q.empty() || q.front() == 0) {
    q.pop_front();
    return NULL;
  }

  Node *root = new Node(q.front());
  q.pop_front();

  root->left = deSerRec(q);
  root->right = deSerRec(q);
  // cout << root->data << " ";
  return root;
}

/*this function deserializes
 the serialized vector A*/
Node *deSerialize(vector<int> &A) {
  // Your code here
  deque<int> q(A.begin(), A.end());
  return deSerRec(q);
}
