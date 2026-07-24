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
    public void fun(TreeNode root,List<Integer>res){
        // base Case 
        if(root==null){
            return;
        }

        fun(root.left,res);                // Left Child ka Traversal 

        res.add(root.val);                 // Root wla Node hi Visit Karlo 

        fun(root.right,res);               // Right wla child ka traversal karlo 
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer>res=new ArrayList<>();

        // Recursive Function call kardo 
        fun(root,res);

        return res;   
    }
}