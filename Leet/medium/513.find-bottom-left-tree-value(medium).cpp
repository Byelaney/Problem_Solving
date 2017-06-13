Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void enorder(TreeNode* root, int depth, int& max_depth, int& left) {
    if (!root) return;
    enorder(root->left, depth+1, max_depth, left);
    if (depth > max_depth) {
        max_depth = depth;
        left = root->val;
    }
    enorder(root->right, depth+1, max_depth, left);
}

int findBottomLeftValue(TreeNode* root) {
    int left = -1;
    int max_depth = -1;
    enorder(root, 0, max_depth, left);
    return left;
}
};
