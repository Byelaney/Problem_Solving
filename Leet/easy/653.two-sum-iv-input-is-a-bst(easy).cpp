Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False

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
    int toAry(vector<int>& v, TreeNode* root) {
    if (root) {
        if (root->left) toAry(v, root->left);
        v.push_back(root->val);
        if (root->right) toAry(v, root->right);
        return root->val;
    }
    else return -1;
}

bool binarySearch(vector<int>& v, int l, int r, int k) {
    int ls = l, re = r;
    while (ls <= re) {
        int mid = (re - ls) / 2 + ls;
        if (v[mid] == k) return true;
        else if (v[mid] > k) re = mid - 1;
        else if (v[mid] < k) ls = mid + 1;
    }
    return false;
}

bool findTarget(TreeNode* root, int k) {
    bool found = false;
    if (root) {
        vector<int> v;
        toAry(v, root);
        for (int i = 0; i < v.size(); ++i) {
            found = binarySearch(v, 0, i - 1, k - v[i]) || binarySearch(v, i + 1, (int) v.size() - 1, k - v[i]);
            if (found) break;
        }
    }
    return found;
}
};
