#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// ! IMP

class GraphNode {
 private:
  string label_;
  unordered_set<GraphNode*> neighbors_;
  string color_;

 public:
  GraphNode(const string& label) : label_(label),
                                   neighbors_(),
                                   color_() {
  }

  const string& getLabel() const {
    return label_;
  }

  const unordered_set<GraphNode*> getNeighbors() const {
    return neighbors_;
  }

  void addNeighbor(GraphNode& neighbor) {
    neighbors_.insert(&neighbor);
  }

  bool hasColor() const {
    return !color_.empty();
  }

  const string& getColor() const {
    if (hasColor()) {
      return color_;
    } else {
      throw logic_error("GraphNode is not marked with color");
    }
  }

  void setColor(const string& color) {
    color_ = color;
  }
};

void colorGraph(const vector<GraphNode*>& graph, const vector<string>& colors) {
  // create a valid coloring for the graph
  for (auto node : graph) {
    const auto& neighbours = node->getNeighbors();

    if (neighbours.find(node) != neighbours.end()) {
      throw "";
    }

    unordered_set<string> illegalColors;
    for (const auto neighbour : neighbours) {
      if (neighbour->hasColor()) {
        illegalColors.insert(neighbour->getColor());
      }
    }

    for (const auto& color : colors) {
      if (illegalColors.find(color) == illegalColors.end()) {
        node->setColor(color);
        break;
      }
    }
  }
}
