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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Condition 1 : Root Node dono ka khali agar hai 
        if(p==nullptr && q==nullptr){
            return true;
        }
        // orr ek null hua toh 
        if(p==nullptr || q==nullptr){
            return false;
        }
        if(p->val!=q->val){
            //agr root wley ka value dono tree mein same nhi hai 
            return false;
        }

        // Left child of the tree k liye same condition karlo 
        bool r1=isSameTree(p->left,q->left);

        // Right child of the tree k liye same condition chk karlo 
        bool r2=isSameTree(p->right,q->right);

        if(r1==true && r2==true){
            return true ;               // agar childs k liye bhi sarey condn hold huye toh true 
        }
        return false;                  // otherwise false 
    }
};