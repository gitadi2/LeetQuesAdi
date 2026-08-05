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

    public boolean isCompleteTree(TreeNode root) {
        // Agar Root hi nhi hai; toh Tree hi gyab hai
        if(root==null){
            return true;               // Khali wla Tree apney liye Complete hi hota hai
        }

        boolean nullFound=false;       // Null Found ko false hi maan k chlo shuruwat mein

        // Level Order Traversal Kartey Raho
        Queue<TreeNode> q=new LinkedList<>();      // Queue ka Dec kardo
        q.offer(root);                             // Queue mei Root Node ko push kardo

        while(!q.isEmpty()){
            // Jab Tak Queue empty nhi hojata
            TreeNode t=q.poll();                   // Queue k Front ko rakhlo t mei

            if(t==null){
                nullFound=true;                    // Phela null mila toh update kardo as true
            }
            else{
                // Node null nhi hai
                if(nullFound){
                    // Null Found jo hai wo true hai
                    return false;                  // Tab false return ho jaega
                }
                // Agar nullFound == false
                q.offer(t.left);                   // Left ko dalo agey badhao
                q.offer(t.right);                  // Right ko dalke agey badha do
            }
        }
        return true;                              // Agar sab shi nikla toh true aajega
    }
}