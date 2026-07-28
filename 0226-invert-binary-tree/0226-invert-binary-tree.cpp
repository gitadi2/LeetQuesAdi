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

    void fun(TreeNode* root){

        // Agar Tree ka main node hi nhi hai
        if(root==nullptr){
            return;
        }

        // Parent Root node bolega apne bachcho ko swap hone
        swap(root->left,root->right);

        // Left Subtree ko invert karlo
        fun(root->left);

        // Right Subtree ko invert karlo
        fun(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        // Recursive Function Call kardo
        fun(root);

        return root;
    }
};