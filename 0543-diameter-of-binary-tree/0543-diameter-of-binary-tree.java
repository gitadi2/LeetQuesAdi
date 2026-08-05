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
    int res=0;                  // Global Variable ; shuru mei resultant 0 hoga 
    public int fun(TreeNode root){
        // Agar root hi null hai; toh tree khaloi hai yni nhi hi hai 
        if(root==null){
            return 0;
        }
        
        // left subtree ka ht.
        int left=fun(root.left);

        // Right Subtree ka height
        int right=fun(root.right);

        int sum=left+right;
        res=Math.max(res,sum);

        return 1+Math.max(left,right);
    }

    public int diameterOfBinaryTree(TreeNode root) {
        // recursive Function call kardo 
        fun(root);

        return res;
    }
}