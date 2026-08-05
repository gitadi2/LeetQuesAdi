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
class Solution {
public:
int res=0;                       // Resultant Global variable shuru mei zero hi hota h

int fun(TreeNode*root){
    // Agar tree ka root hi null hai; ni tree hi nhi hai 
    if(root==nullptr){
        return 0;
    }
    // Ht of the tree (ya Depth nikal lo)
    int left=fun(root->left);           // Left tree k ht nikal lo 
    int right=fun(root->right);         // Right Tree ka Ht. nikal lo 

    int sum=left+right;                 // left subtree ki value + right subtree ki value
    res=max(res,sum);                   // Final Ans mei res and sum se max jio hai wo aaega 

    return 1+max(left,right);
}

    int diameterOfBinaryTree(TreeNode* root) {
        // recursive Function Call kardo 
        fun(root);

        return res;
    }
};