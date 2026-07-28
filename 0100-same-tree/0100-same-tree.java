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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        // agr dono hi root wley null hai 
        if(p==null && q==null){
            return true;            // null hua toh bhi same hi hai 
        }
        // agr ek koi null hua toh false 
        if(p==null || q==null){
            return false;           
        }

        // agar root wla null nhi hai ; toh value se dekhna hoga 
        if(p.val!=q.val){
            return false;
        }

        // Left child k liye bhi same conditions lena hai 
        boolean r1=isSameTree(p.left,q.left);

        // Right child k liye bhi dekhlo hold krta hai ki nhi 
        boolean r2=isSameTree(p.right,q.right);

        // Ab chk krlo ki same hai ki nhi hai right and left bhi
        if(r1==true && r2==true){
            return true;
        }
        return false;            // otherwise wla kaam
    }
}