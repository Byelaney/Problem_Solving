Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.

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
    vector<long> sum;
    vector<long> count;

    void helper(TreeNode* root, vector<long>& sum, vector<long>& count, int depth) {
    if (root) {
        if (sum.size() <= depth) {
            sum.push_back(root->val);
            count.push_back(1);
        }
        else {
            sum[depth] += root->val;
            count[depth] += 1;
        }
        if (root->left) helper(root->left, sum, count, depth+1);
        if (root->right) helper(root->right, sum, count, depth+1);
    }
    }

    vector<double> averageOfLevels(TreeNode* root) {
        helper(root, sum, count, 0);
        vector<double> avg;
        for (int i = 0; i < sum.size(); ++i) {
            double d = 1.0 * sum[i] / count[i];
            avg.push_back(d);
        }
        return avg;
    }
};
