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
    TreeNode* invertTree(TreeNode* root) {
        // agar tree ka main node hi nhi hai 
        if(root==nullptr){
            return nullptr;
        }

        swap(root->left,root->right);                // Parent root node bolega apney child ko swap honey 

        // jsab parent root node wley ke kids swap hogye toh whi bachoo ke bachey bhi toh hongey 
        // left k liye 
        invertTree(root->left);
        // right k liye 
        invertTree(root->right);

        return root;
    }
};