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
unordered_map<int,int>in;                    // HashMap for the Inorder ka index rakhney k liye 
int idx;                                   // Current index of the PostOrder ka 

TreeNode*fun(vector<int>&postorder,int low,int high){
    // Base Case 
    if(low>high){
        return nullptr;
    }
    // Root ko pheley bna lo from postorder ka idx
    TreeNode*root=new TreeNode(postorder[idx]);
    idx--;                               // PostOrder mein hum log peechey pechey aaengey na chlids k liye 

    // Root ko Inorder mei dhunlo 
    int id=in[root->val];

    // Right Subtree of root bna lo from the Inorder 
    root->right=fun(postorder,id+1,high);

    // Left Subtree of the Root bna lo from the Inorder 
    root->left=fun(postorder,low,id-1);

    return root;
}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // HashMap mei index dekhlo 
        for(int i=0;i<inorder.size();i++){
            in[inorder[i]]=i;
        }

        idx=postorder.size()-1;
        
        // Recursive Call karlo 
        return fun(postorder,0,inorder.size()-1);
    }
};