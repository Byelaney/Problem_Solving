Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

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
vector<TreeNode*> dfsBST(TreeNode* root, TreeNode* node) {
    vector<TreeNode*> v;
    if (root == NULL) return v;
    if (root == node) v.push_back(node);
    else {
        vector<TreeNode*> left = dfsBST(root->left, node);
        if (left.size() > 0) {
            left.push_back(root);
            return left;
        }
        vector<TreeNode*> right = dfsBST(root->right, node);
        if (right.size() > 0) {
            right.push_back(root);
            return right;
        }
    }
    return v;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || p == NULL || q == NULL) return root;
    vector<TreeNode*> path1 = dfsBST(root, p);
    vector<TreeNode*> path2 = dfsBST(root, q);
    int cursor1 = path1.size()-1, cursor2 = path2.size()-1;
    while (cursor1 >= 0 && cursor2 >= 0) {
        if (path1[cursor1] == path2[cursor2]) {
            cursor1--; cursor2--;
        }
        else return path1[cursor1 + 1];
    }
    if (cursor1 == -1) return path1[cursor1 + 1];
    if (cursor2 == -1) return path2[cursor2 + 1];
    return root;
}
};


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
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
}
};
