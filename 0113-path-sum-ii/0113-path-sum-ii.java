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
    List<List<Integer>> res=new ArrayList<>();      // Global Variable dec; 2D Array Resultant wla

    public void fun(TreeNode root,int sum,List<Integer> diary,int targetSum){
        // Agar Tree ka Root hi null hai
        if(root==null){
            return;
        }

        sum+=root.val;                              // Sum mei Root k val k sath add kro
        diary.add(root.val);                        // Root ka value Diary mei push kro

        // Agar Leaf Node par aa gya
        if(root.left==null && root.right==null){
            if(sum==targetSum){
                res.add(new ArrayList<>(diary));    // Agar Target achieve hua toh Diary wla Res m daalo
            }
            diary.remove(diary.size()-1);           // Diary se hta k reverse m daalo
            return;
        }

        // Agar Non Leaf Node hai; extend from Leftwards and Rightwards
        fun(root.left,sum,diary,targetSum);         // Left wley se extend kro
        fun(root.right,sum,diary,targetSum);        // Right wley se extend kro

        diary.remove(diary.size()-1);               // Ye Non Leaf wlo k liye bhi toh pop back krna hoga

        return;
    }

    public List<List<Integer>> pathSum(TreeNode root,int targetSum) {

        List<Integer> diary=new ArrayList<>();

        // Recursive Function Call kardo
        fun(root,0,diary,targetSum);

        return res;
    }
}