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
        // agar root hai hi nhi yni tree hi nhi hai 
        if(root==null){
            return 0;
        }

        // left Subtree ka Ht
        int left=fun(root.left);
        // right subtree ka hT
        int right=fun(root.right);

        // return karna hai 
        return 1+Math.max(left,right);
    }

    public int maxDepth(TreeNode root) {
        // Recursive fn call k sath return kro 
        return fun(root);
    }
}