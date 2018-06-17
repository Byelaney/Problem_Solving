Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
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
       public TreeNode buildTree(int[] inorder, int[] postorder) {
           if (inorder.length == 0 || postorder.length == 0) return null;
           int rootVal = postorder[postorder.length - 1];
           int id = 0;
           while (inorder[id] != rootVal) id++;
           TreeNode root = new TreeNode(rootVal);
           TreeNode left = buildTree(Arrays.copyOfRange(inorder, 0, id), Arrays.copyOfRange(postorder, 0, id));
           TreeNode right = buildTree(Arrays.copyOfRange(inorder, id+1, inorder.length), Arrays.copyOfRange(postorder, id, postorder.length-1));
           root.left = left;
           root.right = right;
           return root;
       }
   }
