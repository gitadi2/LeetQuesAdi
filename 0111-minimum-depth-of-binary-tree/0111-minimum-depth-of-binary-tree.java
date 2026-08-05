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
    public int fun(TreeNode root){
        // Agar Root hi null hai; Tree hi gyab hai
        if(root==null){
            return 0;
        }

        // Left Subtree agar nhi hai
        if(root.left==null){
            return 1+fun(root.right);          // Toh Right k node se Height define hogi; Root aur uska Right
        }

        // Agar Right Subtree nhi hai
        if(root.right==null){
            return 1+fun(root.left);           // Toh Tree ki Height Left Subtree se hogi; Root aur uska Left
        }

        // Left Subtree ki Height dekho
        int left=fun(root.left);
        // Right Subtree ki Height dekho
        int right=fun(root.right);

        return 1+Math.min(left,right);
    }

    public int minDepth(TreeNode root) {
        // Recursive Function Call kardo
        return fun(root);
    }
}