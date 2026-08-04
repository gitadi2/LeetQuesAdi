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
    boolean res=false;                          // Shuru mei Global Variable ko false man k chlo
    public void fun(TreeNode root,int sum,int targetSum){
        // Agar Root hi null hai; yani ki Tree hi nhi hai
        if(root==null){
            return;
        }

        sum+=root.val;                         // Shuru mei by default sum 0 hi hai; Path k along sum kardo

        // Agar Leaf hai
        if(root.left==null && root.right==null){
            if(sum==targetSum){
                // Leaf node tak pahunch k Path Sum target k equal mil gya
                res=true;
            }
            return;
        }
        // Agar Non Leaf node hua; toh aagey k nodes Traverse karna hai
        fun(root.left,sum,targetSum);          // Left wley Child ko Traverse krtey rho
        fun(root.right,sum,targetSum);         // Right wley Child ko Traverse kro
    }

    public boolean hasPathSum(TreeNode root,int targetSum) {
        // Recursive Function Call kardo
        fun(root,0,targetSum);

        return res;                            // Final Answer return kardo
    }
}