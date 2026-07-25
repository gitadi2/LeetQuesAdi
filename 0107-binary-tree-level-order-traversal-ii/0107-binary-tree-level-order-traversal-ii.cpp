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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;          // Resultant 2D Array 

        if(root==nullptr){
            // Agar tree ka root hi nhi hai toh tree khali hai 
            return res;    //Starting mein khali hai 
        }

        queue<TreeNode*>q;                // Queue ka Declaration lelo 
        q.push(root);                     // Root queue mei push hoga ; back of the queue se 

        while(!q.empty()){
            int lvlSize=q.size();         // Size Og the Queue Hi lelel ka size hoga 
            vector<int>tmp;               // 1 temporrary array lelo 

            while(lvlSize--){
                TreeNode*t=q.front();
                q.pop();                // front wla dekho jo queue mei ho and usko pop kardo 

                tmp.push_back(t->val);   // data ko temp wley array mein push back kardo 

                // Next level wley nodes k liyte 
                // Left wla 
                if(t->left!=nullptr){
                    q.push(t->left);             // Queue Mein push Kardo left Child ko 
                }
                if(t->right!=nullptr){
                    q.push(t->right);           // Queue Mein Right Child Ko Push Kardo 
                }
            }
            res.push_back(tmp);
        }
        // Leaf se Root lene K liye final Array ko hi reverse Kardo 
        reverse(res.begin(),res.end());

        return res;             //Final Resultand 2D array return Kardo 
    }
};