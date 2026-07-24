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
    public void fun(TreeNode root, List<Integer>res){
        // Base case bna lo; agar tree ka root hi khali hai 
        if(root==null){
            return;
        }

        // Postorder Traversal : Left --> Right --> Root
        // Left child ko lo 
        fun(root.left,res);

        // Right chlid ko lo 
        fun(root.right,res);

        
        // Root ko lo 
        res.add(root.val);
    }

    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer>res=new ArrayList<>();

        // Recursive Call kardo 
        fun(root,res);

        return res;
    }
}