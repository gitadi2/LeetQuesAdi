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
void fun(TreeNode* root,vector<int>&res){
    // Base case lelo ; agar tree ka root empty hai 
    if(root==nullptr){
        return;
    }

    // PostOrder Tree Traversal : left-->right-->root
    // left Child ko lo 
    fun(root->left,res);

    // Right Child ko lo 
    fun(root->right,res);

    // Root node ko visit karo 
    res.push_back(root->val);
}

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;                    // Resultant array lelo ; shuru mei khali hi hoga 
        
        //recursive Function call kardo 
        fun(root,res);
        
        return res;
    }
};