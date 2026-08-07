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

    HashMap<Integer,Integer> in=new HashMap<>();     // HashMap for the Inorder ka index rakhney k liye
    int idx;                                         // Current Index of the PostOrder ka

    public TreeNode fun(int[] postorder,int low,int high){
        // Base Case
        if(low>high){
            return null;
        }

        // Root ko pheley bna lo from PostOrder ka idx
        TreeNode root=new TreeNode(postorder[idx]);
        idx--;                                       // PostOrder mein hum log peechey peechey aaengey na childs k liye

        // Root ko Inorder mei dhundlo
        int id=in.get(root.val);

        // Right Subtree of Root bna lo from the Inorder
        root.right=fun(postorder,id+1,high);

        // Left Subtree of the Root bna lo from the Inorder
        root.left=fun(postorder,low,id-1);

        return root;
    }

    public TreeNode buildTree(int[] inorder,int[] postorder) {
        // HashMap mei Index dekhlo
        for(int i=0;i<inorder.length;i++){
            in.put(inorder[i],i);
        }

        idx=postorder.length-1;

        // Recursive Function Call kardo
        return fun(postorder,0,inorder.length-1);
    }
}