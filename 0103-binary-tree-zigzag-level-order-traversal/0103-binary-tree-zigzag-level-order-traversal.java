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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {

        List<List<Integer>> res=new ArrayList<>();    // Resultant Array bna lo; shuru mei to empty hi hoga

        if(root==null){
            return res;
        }

        Queue<TreeNode> q=new LinkedList<>();
        q.offer(root);

        boolean flag=true;                   // true tab hoga jb direction Left --> Right hogi

        while(!q.isEmpty()){

            int lvlSize=q.size();
            List<Integer> tmp=new ArrayList<>(Collections.nCopies(lvlSize,0));

            int first=0;
            int last=lvlSize-1;

            while(lvlSize-->0){

                TreeNode t=q.poll();

                // Direction ke hisab se store karlo
                if(flag==true){
                    tmp.set(first,t.val);
                    first++;
                }
                else{
                    tmp.set(last,t.val);
                    last--;
                }

                // Left Child ko lo
                if(t.left!=null){
                    q.offer(t.left);
                }

                // Right Child Ko lo
                if(t.right!=null){
                    q.offer(t.right);
                }
            }

            res.add(tmp);

            // Direction Change Karlo
            flag=!flag;
        }

        return res;
    }
}