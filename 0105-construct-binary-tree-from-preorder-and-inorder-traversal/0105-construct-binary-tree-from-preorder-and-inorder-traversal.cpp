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
unordered_map<int,int>in;               // HashMp bna lo as Global variable ; jo id of inorder store karega
int idx=0;                               // current index of preorder hai ; shuru mei toh 0 se hi start hoga

TreeNode*fun(vector<int>&preorder,int low,int high){
    // Base case 
    if(low>high){
        return nullptr;
    }
    // Main Root ko bna lo from the preorder idx
    TreeNode*root=new TreeNode(preorder[idx]);
    idx++;              // preorder k idx ko increment kardo 

    // Root wley ko inorder mei dhundlo 
    int id=in[root->val];

    // Root ka ab Left Subtree Inorder mei se milega 
    root->left=fun(preorder,low,id-1);

    // Root ka Right Subtree bhi inorder se hi kilga 
    root->right=fun(preorder,id+1,high);

    return root;
}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // HashMap mei Index Store krna hai 
        for(int i=0;i<inorder.size();i++){
            in[inorder[i]]=i;
        }

        // Recursive Function Call kardo 
        return fun(preorder,0,inorder.size()-1);
    }
};