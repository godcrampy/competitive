#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;
;

bool canVisitAllRoomsDFS(vector<vector<int>>& rooms) {
  // dfs
  stack<int> to_visit;
  set<int> visited;

  to_visit.push(0);

  while (!to_visit.empty()) {
    int n = to_visit.top();
    to_visit.pop();
    visited.insert(n);

    for (int i : rooms[n]) {
      if (visited.find(i) == visited.end()) {
        // not visited, push this to stack
        to_visit.push(i);
      }
    }
  }

  return visited.size() == rooms.size();
}

bool canVisitAllRoomsBFS(vector<vector<int>>& rooms) {
  // bfs
  queue<int> to_visit;
  set<int> visited;

  to_visit.push(0);

  while (!to_visit.empty()) {
    int n = to_visit.front();
    to_visit.pop();
    visited.insert(n);

    for (int i : rooms[n]) {
      if (visited.find(i) == visited.end()) {
        // not visited, push this to stack
        to_visit.push(i);
      }
    }
  }

  return visited.size() == rooms.size();
}