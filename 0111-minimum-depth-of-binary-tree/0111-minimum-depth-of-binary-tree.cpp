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
int fun(TreeNode*root){
    // Agar root hi null hai ; tree hi gyab hai 
    if(root==nullptr){
        return 0;
    }
    
    // Left subtree agr nhi hai 
    if(root->left==nullptr){
        return 1+fun(root->right);          // toh right k node se ht define hogi ; root or uska immd right
    }
    
    // Agar right subtree nhi hai 
    if(root->right==nullptr){
        return 1+fun(root->left);           // toh tree ka ht. left sub tree se hoga ; root or uska immd left
    }

    // Left subtree ka ht dekho 
    int left=fun(root->left); 
    // Right subtree ka ht dekho 
    int right=fun(root->right);

    return 1+min(left,right);      
}

    int minDepth(TreeNode* root) {
        // Recursive Function call kardo 
        return fun(root);  
    }
};