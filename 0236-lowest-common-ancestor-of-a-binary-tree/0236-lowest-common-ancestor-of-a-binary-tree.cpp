/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
TreeNode* ans=nullptr;              // Global Function lrlo 

int fun(TreeNode*root, TreeNode*p,TreeNode*q){
    // Agar root hai hi nhi toi tree hi obvio nhi hi hai 
    if(root==nullptr){
        return 0;
    }

    // Left wley child ko puchlo ki wo kitney ka boss hai 
    int left=fun(root->left,p,q);
    // Right wley child ko puchlo ki wo kitney ka boss hai 
    int right=fun(root->right,p,q);

    int self=0;           // shuru mei zero init  kardo; y agar self hua uska hai 

    if(root==p || root==q){
        // agar root jo hai wo equate hi ho jta hai; yni wo khud wla hi hai
        self=1;
    }

    int total=self+left+right;               // Total ko update Kardo 

    if(total==2 && ans==nullptr){
        // agr total 2 ata hai and pheli bar ata hai jb ans mein kuvh nhi hai 
        ans=root;         // whi ans hai update kardo 
    }
    return total;         // total jo hoga usko return kardo 
}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Recursive Function Call kardo 
        fun(root,p,q);

        // Final Ans retuirn kardo 
        return ans;
    }
};