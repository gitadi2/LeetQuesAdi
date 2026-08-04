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
bool res=false;                                    // shuru mei global var ko false man k chl lo 
void fun(TreeNode*root, int sum, int targetSum){
    // Agar root hi null hai; yani ki tree hi nhi hai 
    if(root==nullptr){
        return;
    }
    sum+=root->val;                            // shuru mei by default sum 0 hi hai sum kardo path k along 

    // Agar leaf hai 
    if(root->left==nullptr && root->right==nullptr){
        if(sum==targetSum){
            res=true;                // agr leaf node tak pahunch k path sum target k equal mil gya ;ret true
        }
        return;
    }

    // agar Non leaf node hua ; toh agey k nodes traverse karna hai 
    fun(root->left,sum,targetSum);                   // left wley child ko traverse krtey rho
    fun(root->right,sum,targetSum);                  // right wley child ko trav kro 
}

    bool hasPathSum(TreeNode* root, int targetSum) {
        // Recursive Function call kardo 
        fun(root,0,targetSum);

        return res;            // agar target wla mila toh true ret hojaega 
    }
};