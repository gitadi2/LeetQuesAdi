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
void fun(TreeNode* root, vector<int>&res){
    // Base case lelo 
    if(root==nullptr){
        // agar tree hi nahi hai 
        return;
    }

    // Inorder Traversal : Left-->Root node --> right
    fun(root->left,res);              // sbse phle left wley child ko visit karlo 

    // ab Parent node ko visit karlo 
    res.push_back(root->val);

    // ab Right Child ko  dekhlo 
    fun(root->right,res);
}

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;

        // Recursive Function Call kardo 
        fun(root,res);

        // Final resultant array inorder traversal wla return kardo 
        return res; 
    }
};