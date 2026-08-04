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
vector<vector<int>>res;                                    // Global variable dec ; 2D array resultant wla
void fun(TreeNode*root,int sum,vector<int>&diary,int targetSum){
    // Agar tree ka root hi null hai 
    if(root==nullptr){
        return;
    }

    sum+=root->val;                                   // sum mei root k val k sath add kro 
    diary.push_back(root->val);                      // root ka value diary mei  push kro

    // agar leaf node par agya 
    if(root->left==nullptr && root->right==nullptr){
        if(sum==targetSum){
            res.push_back(diary);                     // agar target achieve hua toh diary wla res m dalo 
        }
        diary.pop_back();                         // diary se hta k reverse m dalo 
        return;
    }

    // Agar Non leaf node hai ; extend from leftwards and rightwards 
    fun(root->left,sum,diary,targetSum);                 // Left wley se extend kro 
    fun(root->right,sum,diary,targetSum);                // Right wley se extend kro 

    diary.pop_back();                                    // Y non leaf wlo k liye bhi toh pop back krna hoga 

    return;
}

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> diary;
        
        // Recursivee function call kardo 
        fun(root,0,diary,targetSum);

        return res;
    }
};