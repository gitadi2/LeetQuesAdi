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
    public TreeNode searchBST(TreeNode root, int val) {
        // Agar root node hi gyab hai tohn of tree bhi gyab hoga 
        if(root==null){
            return null;
        }

        // Agar root mei hi mil gya value
        if(root.val==val){
            return root;             // toh whi value return kardo 
        }

        // par agar val root se chotti hai 
        if(val<root.val){
            // Left mei chley jao 
            return searchBST(root.left,val);
        }
        // wrna right mei jao 
        return searchBST(root.right,val);
    }
}