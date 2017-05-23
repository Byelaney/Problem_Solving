Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.

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
void inorder(TreeNode* root, int& val, int& mini) {
    if (!root) return;
    if (root->left)
        inorder(root->left, val, mini);
    if (val != -1) mini = min(mini, root->val - val);
    val = root->val;
    if (root->right)
        inorder(root->right, val, mini);
}

int getMinimumDifference(TreeNode* root) {
    int mini = INT_MAX, val = -1;
    inorder(root, val, mini);
    return mini;
}
};
