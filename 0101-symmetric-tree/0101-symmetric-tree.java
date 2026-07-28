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

    public boolean fun(TreeNode root1, TreeNode root2){
        // root start wla hi null hai dono mei
        if(root1==null && root2==null){
            return true;
        }
        // agar root start wla mei se koi ek hi null hai ; toh ofc symm toh nhi hoga 
        if(root1==null || root2==null){
            return false;
        }
        // agar root present hai; par value diff hai; toh bhi false 
        if(root1.val!=root2.val){
            return false;
        }

        // left child original -> right child in mirror world 
        boolean r1=fun(root1.left,root2.right);
        // right child original -> left child of mirror world
        boolean r2=fun(root1.right,root2.left);

        return (r1 && r2);                   // agar doono true huye tabhi true return hoga 
    }

    public boolean isSymmetric(TreeNode root) {
        // main tree mein se left child ek tree bnega and rt child dusra tree 
        return fun(root.left,root.right);
    }
}