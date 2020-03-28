#include <limits.h>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
  int alive = 0;

  for (auto node : lists) {
    if (node != NULL) {
      ++alive;
    }
  }

  ListNode* d = new ListNode(0);
  auto i = d;

  while (alive) {
    int min_val = INT_MAX;
    int min_pos = 0;

    for (int i = 0; i < lists.size(); ++i) {
      auto node = lists[i];
      if (node != NULL) {
        if (node->val < min_val) {
          min_val = node->val;
          min_pos = i;
        }
      }
    }

    i->next = lists[min_pos];
    i = i->next;
    lists[min_pos] = lists[min_pos]->next;
    if (lists[min_pos] == NULL) {
      --alive;
    }
  }

  return d->next;
}