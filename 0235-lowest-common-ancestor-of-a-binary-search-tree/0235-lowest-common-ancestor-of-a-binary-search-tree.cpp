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
TreeNode* ans=nullptr;               // Global Variable lelo 
void fun(TreeNode*root, TreeNode*p, TreeNode*q){
    // agar tree hai hi nhi yni root null hai 
    if(root==nullptr){
        return;
    }

    if(root==p || root==q){
        // agar root parent hi hai 
        ans=root;
        return;
    }

    if(root->val<p->val){
        // assume maan k chl rhe right se bhi chotta hai; yni parent root sabse chotta hai 
        fun(root->right,p,q);           // left wley pura cancel; right mei dekhlo apna LCA
    }
    else if(root->val>q->val){
        // yha par bhi root wla bnega nhi LCA
        fun(root->left,p,q);
    }
    else{
        // Agar root->val > p->val && root->val < q->val
        // matlab beech mei hai 
        ans=root;
        return;
    }
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // chotti value ko p root bna do 
        if(p->val>q->val){
            swap(p,q);
        }
        
        // recursive Function call kardo 
        fun(root,p,q);

        // return the final ans
        return ans;
    }
};