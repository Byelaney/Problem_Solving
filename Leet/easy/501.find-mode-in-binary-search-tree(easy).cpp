Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.


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
    void dfs(TreeNode* root, unordered_map<int, int>& ump) {
    if (root) {
        ump[root->val] = (ump.count(root->val))?(ump[root->val]+1):1;
        if (root->left) dfs(root->left, ump);
        if (root->right) dfs(root->right, ump);
    }
}

vector<int> findMode(TreeNode* root) {
    vector<int> v;
    unordered_map<int, int> ump;
    dfs(root, ump);
    int max_count = 0;
    for (unordered_map<int, int>::iterator it = ump.begin(); it != ump.end(); ++it) {
        max_count = max(max_count, it->second);
    }
    for (unordered_map<int, int>::iterator it = ump.begin(); it != ump.end(); ++it) {
        if (it->second == max_count) v.push_back(it->first);
    }
    return v;
}
};
