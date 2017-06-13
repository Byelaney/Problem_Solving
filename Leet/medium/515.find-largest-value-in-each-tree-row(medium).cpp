You need to find the largest value in each row of a binary tree.

Example:
Input:

          1
         / \
        3   2
       / \   \
      5   3   9

Output: [1, 3, 9]

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
    void preorder(TreeNode* root, int depth, vector<int>& v) {
    if (!root) return;
    if (v.size() <= depth) {
        v.push_back(root->val);
    }
    else {
        v[depth] = max(v[depth], root->val);
    }
    if (root->left) preorder(root->left, depth + 1, v);
    if (root->right) preorder(root->right, depth + 1, v);
}

vector<int> largestValues(TreeNode* root) {
    vector<int> v;
    preorder(root, 0, v);
    return v;
}
};
