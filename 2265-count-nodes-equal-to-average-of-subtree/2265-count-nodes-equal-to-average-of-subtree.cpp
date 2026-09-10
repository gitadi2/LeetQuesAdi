/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// By DFS Method

class Solution {
public:
    pair<int,int> fun(TreeNode*root,int&res){
        // Base Case
        if(root==nullptr){
            return {0,0};
        }
        // Left subtree ka sum aur count nikal lo
        pair<int,int>left=fun(root->left,res);

        // Right subtree ka sum aur count nikal lo
        pair<int,int>right=fun(root->right,res);

        // Current subtree ka total sum
        int sum=root->val+left.first+right.first;

        // Current subtree mein total nodes
        int cnt=1+left.second+right.second;

        // Average check karo
        if(sum/cnt==root->val){
            res++;
        }
        // Sum aur count return karo
        return {sum,cnt};
    }

    int averageOfSubtree(TreeNode*root){
        int res=0;                         // Answer ko 0 se shuru karo

        // DFS call kardo
        fun(root,res);

        return res;
    }
};