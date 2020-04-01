#include <cmath>
#include <map>

using namespace std;

// IMP
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ! Double is used to pass really large test cases, int is fine
// https://www.youtube.com/watch?v=sm4UdCO2868&list=PLU_sdQYzUj2keVENTP0a5rdykRSgg9Wp-&index=43
map<double, double> m;  // depth to leftmost position
double max_width = 0;

int widthOfBinaryTree(TreeNode* root) {
  get_width(root, 0, 0);
  return max_width;
}

void get_width(TreeNode* root, double depth, double position) {
  if (root == NULL) return;

  if (m.find(depth) == m.end()) {
    m.insert({depth, position});
  }
  max_width = max(max_width, position - m[depth] + 1);

  get_width(root->left, depth + 1, position * 2);
  get_width(root->right, depth + 1, position * 2 + 1);
}