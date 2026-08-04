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
    int res=0;                             // shuru mei 0 se hi lelo res wla 
    public void fun(TreeNode root,int sum){
        // agar tree ka root hi null hai; yni tree hi nhi hai 
        if(root==null){
            return;
        }

        sum=sum*10+root.val;               // jod loo path k along wley nodes k data se root ko bhi 

        // Agar leaf node tak aagya 
        if(root.left==null && root.right==null){
            res+=sum;                       // res ko update krdo sum se 
            return;
        }

        // Agar Non leaf mei hi ho ; tab extend kro left and right mei 
        fun(root.left,sum);
        fun(root.right,sum);

        return;
    }

    public int sumNumbers(TreeNode root) {
        // Recursive Function call kardo 
        fun(root,0);

        return res; 
    }
}