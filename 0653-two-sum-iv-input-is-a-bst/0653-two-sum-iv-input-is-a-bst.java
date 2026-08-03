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
    Stack<TreeNode> asc=new Stack<>();          // Global Stack dec for asc order ele of BST
    Stack<TreeNode> desc=new Stack<>();         // Global Stack dec for desc order ele of BST

    public TreeNode getSmall(){
        if(asc.empty()){
            // Agar Stack khali hai
            return null;
        }

        TreeNode small=asc.peek();              // Sabse chhota wla ele Stack k top par hi rhega
        asc.pop();

        TreeNode rightchild=small.right;        // Dekhlo ki koi Right Child hai kya small wley node ka
        while(rightchild!=null){
            // Jab tak wo Child hai
            asc.push(rightchild);               // Right Child ko Stack mein daal lo
            rightchild=rightchild.left;         // Right Child k sath purey Left wley uskey khandan ko bhi daal lo
        }
        return small;
    }

    public TreeNode getBig(){
        if(desc.empty()){
            // Agar desc wla Stack Empty hua
            return null;
        }

        TreeNode big=desc.peek();               // Stack ka sabse bda ele Stack k top par rahega
        desc.pop();

        TreeNode leftchild=big.left;            // Dekhlo ki koi Left Child hai kya big node ka
        while(leftchild!=null){
            // Jab tak wo Child hai
            desc.push(leftchild);               // Left Child ko Stack mei daal lo
            leftchild=leftchild.right;          // Khandan sath mein chlega
        }
        return big;
    }

    public boolean findTarget(TreeNode root,int k) {
        // Agar Tree ka Root hi null hai toh Tree hi nhi hai
        if(root==null){
            return false;
        }

        TreeNode t=root;                        // Root se hi start hoga
        while(t!=null){
            asc.push(t);                        // Root ko hi push kardo
            t=t.left;                           // Purey Left ko push kartey rho jab tak Left null nhi hojata
        }

        t=root;                                 // Root se wapis restart karo
        while(t!=null){
            desc.push(t);                       // Root ko daalo Stack mei
            t=t.right;                          // Purey Right ko push krtey rho till Right not be null
        }

        TreeNode i=getSmall();                  // Usi Stack mein i shuru ka ptr bnega
        TreeNode j=getBig();                    // Usi Stack mei j last wley ele ka ptr bnega

        while(i!=null && j!=null && i!=j && i.val<=j.val){
            // Jab tak i and j node hold ho i not equal to j h and i ka value j se km ho
            int sum=i.val+j.val;                // Add kro dono k value ko

            if(sum==k){
                return true;
            }
            else if(sum>k){
                j=getBig();
            }
            else{
                i=getSmall();
            }
        }
        return false;                          // Agar hold nhi hua dono cases mein
    }
}