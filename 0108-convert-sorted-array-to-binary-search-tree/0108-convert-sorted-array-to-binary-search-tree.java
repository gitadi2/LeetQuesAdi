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
    public TreeNode fun(int[] nums,int low,int high){
        // Base Case lelo
        if(low>high){
            return null;
        }
        // Root middle wla element hi bnta hai in a Sorted Array
        int mid=(low+high)/2;

        TreeNode root=new TreeNode(nums[mid]);

        // Left Child bna lo
        root.left=fun(nums,low,mid-1);          // Mid element k Left wley Tree mei Left mei aaengey

        // Right Child bna lo
        root.right=fun(nums,mid+1,high);        // Mid element k next element se lekey High tak Right Tree aaega

        return root;
    }

    public TreeNode sortedArrayToBST(int[] nums) {
        // Recursive Function Call karlo
        return fun(nums,0,nums.length-1);
    }
}