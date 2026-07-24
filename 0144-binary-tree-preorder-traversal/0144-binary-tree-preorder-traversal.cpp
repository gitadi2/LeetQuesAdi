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
    // Base case klelo ; agar tree ka root i/p hi nhi hai 
    if(root==nullptr){
        return;
    }

    // Preorder Tree Traversal : Root --> left --> right
    // Root wley ko pheley lelo 
    res.push_back(root->val);

    // Left Child ko lelo 
    fun(root->left,res);

    // Right child ko lelo 
    fun(root->right,res);
}

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;                                 // Resultant Array lelo

        // Recursive Call kardo 
        fun(root,res);

        return res;                                    // Final resultant array of preorder return kardo 
    }
};