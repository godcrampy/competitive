/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// This function should rotate list counter-clockwise
// by k and return new head (if changed)

Node* rotate(Node* head, int k) {
  // Your code herei
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node* last = head;
  while (last->next != NULL) {
    last = last->next;
  }

  Node* i = head;
  --k;
  i = head;
  while (k--) {
    i = i->next;
  }

  last->next = head;
  Node* res = i->next;
  i->next = NULL;
  return res;
}
