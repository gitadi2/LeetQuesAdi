/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {

    TreeNode ans=null;          // Global Function Declare Kardo 

    public int fun(TreeNode root, TreeNode p, TreeNode q){
        // Agar root hi nhi hai ; yni tree nhi hai 
        if(root==null){
            return 0;
        }

        // Left wley child se puchlo kitno ka boss hai p and q nodes mei se 
        int left=fun(root.left,p,q);
        // Right wley child se puchlo kitno ka boss hai p and q nodes me se hi 
        int right=fun(root.right,p,q);

        int self=0;               // khud wla hai toh ye; shuru mei intit krney k liye 0 daal hai 
        if(root==p || root==q){
            self=1;                 // agar wo khud hi p ya q hai toh self hua ; update kardo self ko to 1
        }
        int total=self+left+right;       // Total update kardo utno se bda hoga 

        if(total==2 && ans==null){
            // agar total 2 hai and pheli bar wla 2 mila toh whi ans hoga ; root kop usi mei ans updt. kro
            ans=root;
        }
        return total;
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // Recursive Function call kardo 
        fun(root,p,q);

        // Final ans return kardo 
        return ans;
    }
}