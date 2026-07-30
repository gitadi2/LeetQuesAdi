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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Agar root hi null hai yni tree hi gyab hai 
        if(root==nullptr){
            return nullptr;
        }

        // Agar value search krtey huye root mei hi mil gya 
        if(root->val==val){
            return root;               // usi Node ko hi return kardo 
        }

        // Agar given val root se choti hai ; toh in bst left chley jao 
        if(val<root->val){
            return searchBST(root->left,val);
        }

        // agr bda hua toh ofc as per rules of BST right chley jao
        return searchBST(root->right,val);
    }
};