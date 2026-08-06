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
TreeNode*prev=nullptr;                   // Prev node as Global varible ; shuru mei null hi higa 
int galat=0;                             // Shuru mei glti hui nhi h toh init with 0

TreeNode*g1first=nullptr;
TreeNode*g1second=nullptr;
TreeNode*g2first=nullptr;
TreeNode*g2second=nullptr;

// Inoreder Traversal kardoo
void inorder(TreeNode*root){
    // Agar Tree ka Root hi null hai; yni tree hi nhi hai 
    if(root==nullptr){
        return;
    }
    // Left Child ko mauka do 
    inorder(root->left);

    // Khud Ko mauka dedo 
    if(prev==nullptr){
        // Agar prev noode kch hai hi nhi 
        prev=root;                     // Toh root hi previous bnega 
    }
    else{
        // Agar prev khali nhi hai 
        if(root->val<prev->val){
            // agr root jo prev k baad ati hai uski value choti hui 
            if(galat==0){
                // yni ki glti 1st hai 
                g1first=prev;
                g1second=root;
                galat++;                       // galat ko badhtey rho
            }
            else{
                // yni 1st glti nhi hai 
                g2first=prev;
                g2second=root;
                galat++;
            }
        }
        prev=root;                       // prev ko root se jodkey hi chltey rho 
    }

    // Ab right child ko mauka dedo 
    inorder(root->right);
}

    void recoverTree(TreeNode* root) {
        // Recursive Function call kardo 
        inorder(root);

        if(galat==1){
            // agar ek hi glti hai ; toh adjcent wla case hai unhii do ko swap dalo 
            swap(g1first->val,g1second->val);
        }
        else{
            // 1 se jyada glti hui 
            swap(g1first->val,g2second->val);
        }

        return;
    }
};