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
int res=0;                            // Global ariable lelo ; usko shuru mei se hi 0 se init karo
void fun(TreeNode*root,int sum){
    // agar root hi nhi hai toh tree hi nhi hai 
    if(root==nullptr){
        return;
    }

    sum=sum*10+root->val;                    // path k along jodtey jao uskey liye 

    // agar leaf node hai 
    if(root->left==nullptr && root->right==nullptr){
        res+=sum;                                // sum jo bhi aaega usko res mein uopdate kro 
        return;
    }

    // Agar Non leaf node hai ; toh left and right ki orr extend krtey chlo 
    fun(root->left,sum);                  // left mei chlo 
    fun(root->right,sum);                 //right mei chloo

    return; 
}

    int sumNumbers(TreeNode* root) {
        // recursive Function call kardo 
        fun(root,0);

        return res;
    }
};