#include <limits.h>

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int number_of_nodes = 5;

typedef struct node {
  int position;
  int distance;
  struct node* next = NULL;
} node;

void connect_nodes(node* list[number_of_nodes], int a, int b, int distance);
void bfs(node* list[number_of_nodes], int a);
void dfs(node* list[number_of_nodes], int a);
int djikstras(node* list[number_of_nodes], int start, int end);

int main(int argc, char const* argv[]) {
  // * initialise list
  node* list[number_of_nodes];
  for (int i = 0; i < number_of_nodes; ++i) {
    list[i] = new node;
  }

  // * Connect nodes
  connect_nodes(list, 0, 1, 10);
  connect_nodes(list, 0, 2, 15);
  connect_nodes(list, 1, 2, 5);
  connect_nodes(list, 1, 3, 20);
  connect_nodes(list, 2, 3, 7);
  connect_nodes(list, 3, 4, 8);
  connect_nodes(list, 2, 4, 4);

  // bfs(list, 0);
  // dfs(list, 0);
  cout << djikstras(list, 0, 3) << endl;

  return 0;
}

node* _last_node(node* iterator) {
  while (iterator->next != NULL) {
    iterator = iterator->next;
  }
  return iterator;
}

void connect_nodes(node* list[number_of_nodes], int a, int b, int distance) {
  // * connect b to a
  node* iterator = _last_node(list[b]);
  node* node_1 = new node;
  node_1->position = a;
  node_1->distance = distance;
  iterator->next = node_1;

  // * connect a to b
  iterator = _last_node(list[a]);
  node* node_2 = new node;
  node_2->position = b;
  node_2->distance = distance;
  iterator->next = node_2;
}

void bfs(node* list[number_of_nodes], int a) {
  queue<int> queue;
  bool visited_queue[number_of_nodes];
  for (int i = 0; i < number_of_nodes; ++i) {
    visited_queue[i] = false;
  }
  queue.push(a);
  visited_queue[a] = true;
  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();
    cout << front << " ";
    node* iterator = list[front]->next;
    while (iterator != NULL) {
      if (!visited_queue[iterator->position]) {
        queue.push(iterator->position);
        visited_queue[iterator->position] = true;
      }
      iterator = iterator->next;
    }
  }
  cout << endl;
}

void dfs(node* list[number_of_nodes], int a) {
  stack<int> stack;
  bool visited_stack[number_of_nodes];
  for (int i = 0; i < number_of_nodes; ++i) {
    visited_stack[i] = false;
  }
  stack.push(a);
  visited_stack[a] = true;
  while (!stack.empty()) {
    int top = stack.top();
    stack.pop();
    cout << top << " ";
    node* iterator = list[top]->next;
    while (iterator != NULL) {
      if (!visited_stack[iterator->position]) {
        stack.push(iterator->position);
        visited_stack[iterator->position] = true;
      }
      iterator = iterator->next;
    }
  }
  cout << endl;
}

int djikstras(node* list[number_of_nodes], int start, int end) {
  bool visited[number_of_nodes];
  int distance[number_of_nodes];
  int previous[number_of_nodes];
  for (int i = 0; i < number_of_nodes; ++i) {
    visited[i] = false;
    distance[i] = INT_MAX;
    previous[i] = -1;
  }
  int current_node = start;
  distance[current_node] = 0;
  int next_node;
  while (current_node != -1) {
    //* visit current node
    int next_node = -1;
    int min_distance = INT_MAX;
    visited[current_node] = true;
    node* iterator = list[current_node]->next;
    while (iterator != NULL) {
      int node = iterator->position;
      int dist = iterator->distance;
      if (!visited[node] && distance[node] >= distance[current_node] + dist) {
        distance[node] = distance[current_node] + dist;
        if (dist < min_distance) {
          next_node = node;
          min_distance = dist;
        }
      }
      iterator = iterator->next;
    }
    current_node = next_node;
  }
  return distance[end];
}
