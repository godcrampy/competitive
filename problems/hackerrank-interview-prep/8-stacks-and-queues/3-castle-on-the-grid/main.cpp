#include <bits/stdc++.h>

using namespace std;

// Complete the minimumMoves function below.
int minimumMoves(vector<string> &grid, int startX, int startY, int goalX,
                 int goalY) {
  int xSize = grid.size();
  int ySize = grid[0].size();
  vector<vector<bool>> visited(grid.size(),
                               vector<bool>(grid[0].size(), false));
  queue<pair<int, pair<int, int>>> q;  // distance from start, coords
  q.push({0, {startX, startY}});
  visited[startX][startY] = true;
  while (!q.empty()) {
    int distance = q.front().first;
    int pX = q.front().second.first;
    int pY = q.front().second.second;
    q.pop();

    // check left child
    int nextX = pX;
    while (nextX + 1 < xSize && grid[nextX + 1][pY] != 'X') {
      ++nextX;
    }
    for (int i = pX; i <= nextX; ++i) {
      if (!visited[i][pY]) {
        if (i == goalX && pY == goalY) {
          return distance + 1;
        }
        q.push({distance + 1, {i, pY}});
        visited[i][pY] = true;
      }
    }

    // check right child
    nextX = pX;
    while (nextX - 1 >= 0 && grid[nextX - 1][pY] != 'X') {
      --nextX;
    }
    for (int i = pX; i >= nextX; --i) {
      if (!visited[i][pY]) {
        if (i == goalX && pY == goalY) {
          return distance + 1;
        }
        q.push({distance + 1, {i, pY}});
        visited[i][pY] = true;
      }
    }

    // check bottom
    int nextY = pY;
    while (nextY + 1 < ySize && grid[pX][nextY + 1] != 'X') {
      ++nextY;
    }
    for (int i = pY; i <= nextY; ++i) {
      if (!visited[pX][i]) {
        if (i == goalY && pX == goalX) {
          return distance + 1;
        }
        q.push({distance + 1, {pX, i}});
        visited[pX][i] = true;
      }
    }

    // check up
    nextY = pY;
    while (nextY - 1 >= 0 && grid[pX][nextY - 1] != 'X') {
      --nextY;
    }
    for (int i = pY; i >= nextY; --i) {
      if (!visited[pX][i]) {
        if (i == goalY && pX == goalX) {
          return distance + 1;
        }
        q.push({distance + 1, {pX, i}});
        visited[pX][i] = true;
      }
    }
  }
  return -1;
}
