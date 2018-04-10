Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

   /**
    * Definition for a binary tree node.
    * public class TreeNode {
    *     int val;
    *     TreeNode left;
    *     TreeNode right;
    *     TreeNode(int x) { val = x; }
    * }
    */
   class Solution {
       public TreeNode buildTree(int[] preorder, int[] inorder) {
           if (preorder.length == 0 || inorder.length == 0) return null;
           int rootVal = preorder[0];
           int id = 0;
           while (inorder[id] != rootVal) id++;
           TreeNode root = new TreeNode(rootVal);
           TreeNode left = buildTree(Arrays.copyOfRange(preorder, 1, id+1), Arrays.copyOfRange(inorder, 0, id));
           TreeNode right = buildTree(Arrays.copyOfRange(preorder, id+1, preorder.length), Arrays.copyOfRange(inorder, id+1, inorder.length));
           root.left = left;
           root.right = right;
           return root;
       }
   }
