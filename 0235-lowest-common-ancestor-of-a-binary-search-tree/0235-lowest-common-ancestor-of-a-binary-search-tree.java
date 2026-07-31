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

    TreeNode ans=null;               // Global Variable lelo

    public void fun(TreeNode root,TreeNode p,TreeNode q){
        // Agar Tree hai hi nhi yni root null hai
        if(root==null){
            return;
        }

        if(root==p || root==q){
            // Agar root parent hi hai
            ans=root;
            return;
        }

        if(root.val<p.val){
            // Assume maan k chl rhe right se bhi chotta hai; yni parent root sabse chotta hai
            fun(root.right,p,q);          // Left wla pura cancel; Right mei dekhlo apna LCA
        }
        else if(root.val>q.val){
            // Yha par bhi root wla bnega nhi LCA
            fun(root.left,p,q);
        }
        else{
            // Agar root.val > p.val && root.val < q.val
            // Matlab beech mei hai
            ans=root;
            return;
        }
    }

    public TreeNode lowestCommonAncestor(TreeNode root,TreeNode p,TreeNode q) {

        // Chhoti value ko p root bna do
        if(p.val>q.val){
            TreeNode temp=p;
            p=q;
            q=temp;
        }

        // Recursive Function Call kardo
        fun(root,p,q);

        // Return the Final Answer
        return ans;
    }
}