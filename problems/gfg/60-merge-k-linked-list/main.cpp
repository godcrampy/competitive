struct compare {
  bool operator()(struct Node* a, struct Node* b) { return a->data > b->data; }
};

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
Node* mergeKLists(Node* arr[], int N) {
  // Your code here
  priority_queue<Node*, vector<Node*>, compare> q;

  for (int i = 0; i < N; ++i) {
    q.push(arr[i]);
  }

  Node* d = new Node(0);
  Node* i = d;

  while (!q.empty()) {
    auto n = q.top();
    q.pop();
    i->next = n;
    i = i->next;
    if (n->next != NULL) {
      q.push(n->next);
    }
  }

  return d->next;
}
