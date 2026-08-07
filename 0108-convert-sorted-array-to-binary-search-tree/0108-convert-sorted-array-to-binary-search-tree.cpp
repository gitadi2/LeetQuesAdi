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
TreeNode*fun(vector<int>&nums,int low,int high){
    // Base Case lelo 
    if(low>high){
        return nullptr;
    }
    // Root middle wla element hi bnta hai in a sorted array 
    int mid=(low+high)/2;

    TreeNode*root=new TreeNode(nums[mid]); 

    // Left Child bnaq hai 
    root->left=fun(nums,low,mid-1);         // Mid element k left wley tree mei left  mei aaengey 

    // Right Child bna loo
    root->right=fun(nums,mid+1,high);       // Mid element k ext element se lekey high tak right tree aaega 

    return root;
}

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Recursive Function call karloo
        return fun(nums,0,nums.size()-1);
    }
};