#include <limits.h>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int number_of_nodes = 5;

void connect_nodes(int matrix[number_of_nodes][number_of_nodes], int a, int b, int distance);
void print_matrix(int matrix[number_of_nodes][number_of_nodes]);
void bfs(int matrix[number_of_nodes][number_of_nodes], int a);
void dfs(int matrix[number_of_nodes][number_of_nodes], int a);
int djikstras(int matrix[number_of_nodes][number_of_nodes], int start, int end);

int main(int argc, char const *argv[]) {
  int matrix[number_of_nodes][number_of_nodes];

  // * Initialise matrix
  for (int i = 0; i < number_of_nodes; ++i) {
    for (int j = 0; j < number_of_nodes; ++j) {
      matrix[i][j] = 0;
    }
  }

  // * Connect nodes
  connect_nodes(matrix, 0, 1, 10);
  connect_nodes(matrix, 0, 2, 15);
  connect_nodes(matrix, 1, 2, 5);
  connect_nodes(matrix, 1, 3, 20);
  connect_nodes(matrix, 2, 3, 7);
  connect_nodes(matrix, 3, 4, 8);
  connect_nodes(matrix, 2, 4, 4);

  print_matrix(matrix);
  cout << djikstras(matrix, 0, 3) << endl;
  bfs(matrix, 0);
  dfs(matrix, 0);
  return 0;
}

void connect_nodes(int matrix[number_of_nodes][number_of_nodes], int a, int b, int distance) {
  *(*(matrix + a) + b) = distance;
  *(*(matrix + b) + a) = distance;
}

void print_matrix(int matrix[number_of_nodes][number_of_nodes]) {
  for (int i = 0; i < number_of_nodes; ++i) {
    for (int j = 0; j < number_of_nodes; ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

void bfs(int matrix[number_of_nodes][number_of_nodes], int a) {
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
    for (int i = 0; i < number_of_nodes; ++i) {
      int next = matrix[front][i];
      if (next != 0 && !visited_queue[i]) {
        queue.push(i);
        visited_queue[i] = true;
      }
    }
  }
  cout << endl;
}

void dfs(int matrix[number_of_nodes][number_of_nodes], int a) {
  stack<int> stack;
  bool visited_stack[number_of_nodes];
  for (int i = 0; i < number_of_nodes; ++i) {
    visited_stack[i] = false;
  }
  stack.push(a);
  visited_stack[a] = true;
  while (!stack.empty()) {
    int front = stack.top();
    stack.pop();
    cout << front << " ";
    for (int i = 0; i < number_of_nodes; ++i) {
      int next = matrix[front][i];
      if (next != 0 && !visited_stack[i]) {
        stack.push(i);
        visited_stack[i] = true;
      }
    }
  }
  cout << endl;
}

int djikstras(int matrix[number_of_nodes][number_of_nodes], int start, int end) {
  typedef struct row {
    bool visited;
    int node;
    int distance;
    int previous_node;
  } row;
  row table[number_of_nodes];
  for (int i = 0; i < number_of_nodes; ++i) {
    table[i].visited = false;
    table[i].node = i;
    table[i].distance = INT_MAX;
  }
  table[start].distance = 0;
  int current_vertex = start;
  table[start].visited = true;
  int next_node = -1;              // the next node we will visit
  int minimum_distance = INT_MAX;  // minimum distance of all the next node
  while (current_vertex != -1) {
    table[current_vertex].visited = true;
    next_node = -1;
    minimum_distance = INT_MAX;
    for (int i = 0; i < number_of_nodes; ++i) {
      if (matrix[current_vertex][i] != 0 && !table[i].visited) {
        // there is a connection and the node is not visited
        if (table[i].distance >= table[current_vertex].distance + matrix[current_vertex][i]) {
          // rewrite this row
          int min = table[current_vertex].distance + matrix[current_vertex][i];
          table[i].distance = min;
          table[i].previous_node = current_vertex;
          if (min < minimum_distance) {
            minimum_distance = min;
            next_node = i;
          }
        }
      }
    }
    current_vertex = next_node;
  }
  return table[end].distance;
}
