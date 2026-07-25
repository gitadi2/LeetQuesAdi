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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>>res=new ArrayList<>();                    // Resultant List 

        if(root==null){
            return res;            // Agar tree hai hi nhi mtlb uska root 
        }

        Queue<TreeNode>q=new LinkedList<>();           // Queue Declaration
        q.offer(root);                                 // Root ko pheley push kardo 

        while(!q.isEmpty()){
            int lvlSize=q.size();
            List<Integer>tmp=new ArrayList<>();           // Empty hoga start mei

            while(lvlSize-->0){
                TreeNode t=q.peek();
                q.poll();
                tmp.add(t.val);

                if(t.left!=null){
                    q.offer(t.left);
                }
                if(t.right!=null){
                    q.offer(t.right);
                }
            }
            res.add(tmp);
        }
        return res;
    }
}