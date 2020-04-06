#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// ? Singly Linked List Boiler
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* arrayToList(const vector<int>& v) {
  if (v.size() == 0) return NULL;
  ListNode* dummy = new ListNode(0);
  ListNode* itr = dummy;
  for (int n : v) {
    itr->next = new ListNode(n);
    itr = itr->next;
  }
  return dummy->next;
}

void printList(ListNode* head) {
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}
// ? End of Single Linked List Boiler

int getLength(ListNode* head) {
  int count = 0;
  while (head != NULL) {
    head = head->next;
    ++count;
  }
  return count;
}

ListNode* kthFromLast(ListNode* head, int k) {
  // * Time: O(n)
  // * Space: O(1)
  int n = getLength(head);
  int count = n - k;
  while (head != NULL && count > 0) {
    head = head->next;
    --count;
  }
  return head;
}

ListNode* kthFromLastRec(ListNode* head, int k, int& i) {
  // * Time: O(n)
  // * Space: O(k)
  if (head == NULL) {
    return head;
  }

  auto temp = kthFromLastRec(head->next, k, i);
  ++i;
  if (i == k) {
    return head;
  }
  return temp;
}

ListNode* kthFromLastRec(ListNode* head, int k) {
  int i = 0;
  return kthFromLastRec(head, k, i);
}

int main(int argc, char const* argv[]) {
  /* code */
  vector<int> v = {7, 5, 6, 1, 6, 9, 5};
  ListNode* head = arrayToList(v);
  cout << kthFromLastRec(head, 2)->val << endl;
  return 0;
}
