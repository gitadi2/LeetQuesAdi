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
    TreeNode prev=null;                    // Prev Node as Global Variable; shuru mei null hi hoga
    int galat=0;                           // Shuru mei glti hui nhi h toh init with 0

    TreeNode g1first=null;
    TreeNode g1second=null;
    TreeNode g2first=null;
    TreeNode g2second=null;

    // Inorder Traversal kardo
    public void inorder(TreeNode root){
        // Agar Tree ka Root hi null hai; yni Tree hi nhi hai
        if(root==null){
            return;
        }

        // Left Child ko mauka do
        inorder(root.left);

        // Khud Ko mauka dedo
        if(prev==null){
            // Agar Prev Node kch hai hi nhi
            prev=root;                     // Toh Root hi Previous bnega
        }
        else{
            // Agar Prev khali nhi hai
            if(root.val<prev.val){
                // Agar Root jo Prev k baad aati hai uski value choti hui
                if(galat==0){
                    // Yni ki glti 1st hai
                    g1first=prev;
                    g1second=root;
                    galat++;               // Galat ko badhtey rho
                }
                else{
                    // Yni 1st glti nhi hai
                    g2first=prev;
                    g2second=root;
                    galat++;
                }
            }
            prev=root;                    // Prev ko Root se jodkey hi chltey rho
        }

        // Ab Right Child ko mauka dedo
        inorder(root.right);
    }

    public void recoverTree(TreeNode root) {
        // Recursive Function Call kardo
        inorder(root);

        if(galat==1){
            // Agar ek hi glti hai; toh Adjacent wla case hai unhi do ko swap dalo
            int temp=g1first.val;
            g1first.val=g1second.val;
            g1second.val=temp;
        }
        else{
            // 1 se jyada glti hui
            int temp=g1first.val;
            g1first.val=g2second.val;
            g2second.val=temp;
        }

        return;
    }
}