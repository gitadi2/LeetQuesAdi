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
bool fun(TreeNode* root1, TreeNode* root2){
    // agar root wla node khali hai dono hi mei 
    if(root1==nullptr && root2==nullptr){
        return true;
    }
    // agar ek hi koi null hai ; toh symmetric toh bnefga nhi 
    if(root1==nullptr || root2==nullptr){
        return false;
    }

    // ab root ka value hi alg hpo
    if(root1->val!=root2->val){
        return false;
    }

    // ab left child of original cmprd to right child of the miirror world
    bool r1=fun(root1->left,root2->right);

    // ab right child of original compare hoga left child of the mirror world ke 
    bool r2=fun(root1->right,root2->left);

    return (r1 && r2);                  // ye return tabhi hoga jab dono true ho otherwise false aaega
}

    bool isSymmetric(TreeNode* root) {
        // Uska left child ek tree mno and dusra right child dusra tree
        return fun(root->left,root->right);
    }
};