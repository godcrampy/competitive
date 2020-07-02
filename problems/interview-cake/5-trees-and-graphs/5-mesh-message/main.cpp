#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> reconstructPath(
    const unordered_map<string, string>& previousNodes, const string& endNode) {
  vector<string> reversedShortestPath;

  // start from the end of the path and work backwards
  string currentNode = endNode;

  while (!currentNode.empty()) {
    reversedShortestPath.push_back(currentNode);
    currentNode = previousNodes.find(currentNode)->second;
  }

  // reverse our path to get the right order
  // by flipping it around, in place
  reverse(reversedShortestPath.begin(), reversedShortestPath.end());
  return reversedShortestPath;  // no longer reversed
}

vector<string> getPath(const unordered_map<string, vector<string>>& graph,
                       const string& startNode, const string& endNode) {
  // find the shortest route in the network between the two users
  if (graph.find(startNode) == graph.end()) {
    throw "";
  }

  if (graph.find(endNode) == graph.end()) {
    throw "";
  }

  deque<string> nodesToVisit;
  nodesToVisit.push_back(startNode);

  unordered_map<string, string> nodeToParent;
  nodeToParent.insert({startNode, ""});

  while (!nodesToVisit.empty()) {
    auto node = nodesToVisit.front();
    nodesToVisit.pop_front();

    if (node == endNode) {
      return reconstructPath(nodeToParent, endNode);
    }

    for (const auto& neighbour : graph.find(node)->second) {
      if (nodeToParent.find(neighbour) == nodeToParent.end()) {
        nodesToVisit.push_back(neighbour);
        nodeToParent.insert({neighbour, node});
      }
    }
  }

  return vector<string>();
}
