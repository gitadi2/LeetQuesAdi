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
int fun(TreeNode* root){
    // Agar root hi null hai; yni tree hi nhi hai 
    if(root==nullptr){
        return 0;
    }

    // Left Subtree ka ht
    int left=fun(root->left);
    // Right Subtree ka depth
    int right=fun(root->right);

    // wo node root wla k sath milkar ht hogi
    return 1+max(left,right);
}
    int maxDepth(TreeNode* root) {
        // recursive Function call ka sath hi return kro 
        return fun(root);
    }
};