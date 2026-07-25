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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;                        // Resultant Array ko store karne k liye jo 2D hai 

        if(root==nullptr){
            // Agar Tree ka Root node hi nhi hai; yni tree hi nhi hai 
            return res;                // Simply return kardo 
        }

        queue<TreeNode*>q;                              // Queue Ka Declaration lelo 
        q.push(root);                                   // Root ko push kardo queue mein back se push hoga 

        while(!q.empty()){
            int lvlSize=q.size();                       // Current wley ka Level Size kitna hai
            vector<int>tmp;                             // Tmp array bnega empty wlaa 

            // Ab Level Order Traversal Krna hai 
            while(lvlSize--){
                TreeNode*t=q.front();                   //Front mei jo hai 
                q.pop();                                // Queue Se pop kardo

                tmp.push_back(t->val);                   // tmp wley array mein value ko push karo

                // Ab ext wley Level Lelo 
                if(t->left!=nullptr){
                    q.push(t->left);               // agar left wla child hai to usi ko queue mein push kardo
                }
                if(t->right!=nullptr){
                    q.push(t->right);               // agar rt wla child hai to push into the qiueue
                }
            }
            res.push_back(tmp);                    // tmp wley mein stored chezeinn resultant mein daldo
        }
        return res;                                // resultant Array ko return kardo 
    }
};