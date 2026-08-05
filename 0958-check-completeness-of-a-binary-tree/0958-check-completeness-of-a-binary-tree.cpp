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
    bool isCompleteTree(TreeNode* root) {
        // agar  root hi nhi hai; toh tree hi gyb hai 
        if(root==nullptr){
            return true;               // khali wla tree apney liye xomplete hi hota hai
        }

        bool nullFound=false;          // Null Found ko false hi maan k chlo shuruwat mein 

        // Level Order Traversal Kartey Raho 
        queue<TreeNode*>q;                      // queue ka Dec kardo 
        q.push(root);                           // Queue mei Root node ko push kardo 

        while(!q.empty()){
            // Jab Tak queue empty nhi hoijta 
            TreeNode*t=q.front();                  // Queue k front ko rakhlo t mei
            q.pop();                               // Jo front par hai whi pop hoga 

            if(t==nullptr){
                nullFound=true;                    // Phela null mila toh update kardo as true 
            }
            else{
                // Node not null hai 
                if(nullFound){
                    // null found jo hai wo true hai 
                    return false;                   // tab false return ho jaega 
                }
                // agar nullFound==false 
                q.push(t->left);                    // Left ko dalo agey badhao
                q.push(t->right);                   // righ ko dalkey agey badjha doo
            }
        }
        return true;                              // agar  sab shi nikla toh true aajega 
    }
};