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
        // Base case lelo 
        if(root==null){
            return;
        }

        // Preorder Tree Traversal : root-->left-->right
        // Root ko dal do 
        res.add(root.val);

        // Left child ko lo 
        fun(root.left,res);

        // Right Child ko lo 
        fun(root.right,res);
    }

    public List<Integer> preorderTraversal(TreeNode root) {

        List<Integer>res=new ArrayList<>();           // Resultant wla araay bna do list jesa 

        // Recursive Functyion call kardo 
        fun(root,res);

        return res;   
    }
}