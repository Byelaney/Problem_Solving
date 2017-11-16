Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:
Input:
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
Input:
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.

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
     void helperCst(TreeNode* root, int& mini, int& secMini, int& mini_counts, int& node_counts) {
    if (root == NULL) return;
    if (root->val < mini) {
        secMini = mini;
        mini = root->val;
        mini_counts = 1;
    }
    else if (root->val == mini) mini_counts++;
    else if (root->val < secMini) {
        secMini = root->val;
    }
    node_counts++;
    helperCst(root->left, mini, secMini, mini_counts, node_counts);
    helperCst(root->right, mini, secMini, mini_counts, node_counts);
}

int findSecondMinimumValue(TreeNode* root) {
    int mini = INT_MAX, secMini = INT_MAX, mini_counts = 0, node_counts = 0;
    helperCst(root, mini, secMini, mini_counts, node_counts);
    if (mini_counts == node_counts || mini == secMini) return -1;
    else return secMini;
}
};
