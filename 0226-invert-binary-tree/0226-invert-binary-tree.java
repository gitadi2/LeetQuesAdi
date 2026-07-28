/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {

    public void fun(TreeNode root){

        // Agar Tree ka main node hi nhi hai
        if(root==null){
            return;
        }

        // Parent Root node bolega apne bachcho ko swap hone
        TreeNode temp=root.left;
        root.left=root.right;
        root.right=temp;

        // Left Subtree ko invert karlo
        fun(root.left);

        // Right Subtree ko invert karlo
        fun(root.right);
    }

    public TreeNode invertTree(TreeNode root) {

        // Recursive Function Call kardo
        fun(root);

        return root;
    }
}