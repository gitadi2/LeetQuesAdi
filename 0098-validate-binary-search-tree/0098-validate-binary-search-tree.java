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
    TreeNode prev=null;                       // Previous Node ka val store krney k liye; shuru mei null hoga
    boolean ans=true;                         // Ans shuru mei shi hai yni valid hai

    // Inorder Traversal krna hai
    public void inorder(TreeNode root){
        // Agar Root hi null hai; yni Tree hi nhi hai
        if(root==null){
            return;
        }

        // Left Child ko mauka dedo
        inorder(root.left);

        // Khud ko mauka dedo
        if(prev==null){
            // Yni ki first node hai
            prev=root;                        // Root bna loo
        }
        else{
            if(root.val<=prev.val){
                // Agar Root se Prev bda hai; tab toh BST hold nhi hoga
                ans=false;
            }
            prev=root;
        }

        // Right Child ko mauka Dedo
        inorder(root.right);
    }

    public boolean isValidBST(TreeNode root) {
        // Recursive Function Call karo
        inorder(root);

        return ans;
    }
}