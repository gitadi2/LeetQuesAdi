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
TreeNode* prev=nullptr;                       // Previous Node ka val store krney k liye ; shuru mei 0 hoga
bool ans=true;                               // ans khali hai and shuru mei shi hai yni valid hai

// Inoreder trversal krna hai 
void inorder(TreeNode*root){
    // Agar root hi null hai; ynhi tree hi nhi hai
    if(root==nullptr){
        return;
    }

    // Left child ko mauka dedo 
    inorder(root->left);

    // Khud ko mauka dedo 
    if(prev==nullptr){
        // yni ki first node hai 
        prev=root;                              // root bna loo 
    }
    else{
        if(root->val<=prev->val){
            // Agar root se prev bda hai; tab toh BST hold nhi hoga 
            ans=false;
        }
        prev=root;
    }

    // Right Child Ko mauka Dedo
    inorder(root->right);
}

    bool isValidBST(TreeNode* root) {
        // Recursive Function Call karo 
        inorder(root);

        return ans;  
    }
};