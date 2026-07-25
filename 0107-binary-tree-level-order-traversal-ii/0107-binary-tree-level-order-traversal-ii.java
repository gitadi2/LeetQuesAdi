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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {

        List<List<Integer>> res=new ArrayList<>();          // Resultant 2D Array

        if(root==null){
            // Agar tree ka root hi nhi hai toh tree khali hai
            return res;    // Starting mein khali hai
        }

        Queue<TreeNode> q=new LinkedList<>();               // Queue ka Declaration lelo
        q.offer(root);                                      // Root queue mei push hoga; back of the queue se

        while(!q.isEmpty()){

            int lvlSize=q.size();                           // Size of the Queue hi level ka size hoga
            List<Integer> tmp=new ArrayList<>();            // 1 temporary array lelo

            while(lvlSize-->0){

                TreeNode t=q.poll();                    // Front wla dekho jo queue mei ho and usko pop kardo

                tmp.add(t.val);                             // Data ko temp wley array mein push kardo

                // Next level wley nodes k liye
                // Left wla
                if(t.left!=null){
                    q.offer(t.left);                        // Queue Mein push Kardo left Child ko
                }

                if(t.right!=null){
                    q.offer(t.right);                       // Queue Mein Right Child Ko Push Kardo
                }
            }
            res.add(tmp);
        }
        // Leaf se Root lene K liye final Array ko hi reverse Kardo
        Collections.reverse(res);

        return res;             // Final Resultant 2D array return Kardo
    }
}