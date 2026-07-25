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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;    //Resultant Array bna lo ; shuru mei to empty hi hoga 

        if(root==nullptr){
            return res;
        }
        
        queue<TreeNode*>q;
        q.push(root);

        bool flag=true;                   // true tab hoga jb direction left --> right hogi 

        while(!q.empty()){
            int lvlSize=q.size();
            vector<int>tmp(lvlSize);

            int first=0;
            int last=lvlSize-1;

            while(lvlSize--){
                TreeNode*t=q.front();
                q.pop();

                // Direction ke hisab se store karlo 
                if(flag==true){
                    tmp[first]=t->val;
                    first++;
                }
                else{
                    tmp[last]=t->val;
                    last--;
                }

                // Left Child ko lo 
                if(t->left!=nullptr){
                    q.push(t->left);
                }
                // Right Child Ko lo 
                if(t->right!=nullptr){
                    q.push(t->right);
                }
            }
            res.push_back(tmp);

            // Direction Change Karlo 
            flag=1-flag;
        }
        return res;
    }
};