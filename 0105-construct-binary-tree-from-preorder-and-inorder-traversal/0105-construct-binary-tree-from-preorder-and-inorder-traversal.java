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
    HashMap<Integer,Integer> in=new HashMap<>();  
    int idx=0;                           // Current Index of Preorder hai; shuru mei toh 0 se hi start hoga

    public TreeNode fun(int[] preorder,int low,int high){
        // Base Case
        if(low>high){
            return null;
        }

        // Main Root ko bna lo from the Preorder idx
        TreeNode root=new TreeNode(preorder[idx]);
        idx++;                                      // Preorder k idx ko increment kardo

        // Root wley ko Inorder mei dhundlo
        int id=in.get(root.val);

        // Root ka ab Left Subtree Inorder mei se milega
        root.left=fun(preorder,low,id-1);

        // Root ka Right Subtree bhi Inorder se hi milega
        root.right=fun(preorder,id+1,high);

        return root;
    }

    public TreeNode buildTree(int[] preorder,int[] inorder) {
        // HashMap mei Index Store krna hai
        for(int i=0;i<inorder.length;i++){
            in.put(inorder[i],i);
        }

        // Recursive Function Call kardo
        return fun(preorder,0,inorder.length-1);
    }
}