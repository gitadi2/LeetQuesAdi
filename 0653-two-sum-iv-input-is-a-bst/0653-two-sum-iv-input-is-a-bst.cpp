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
stack<TreeNode*>asc;                             // global stack dec for asc order ele of bst 
stack<TreeNode*>desc;                            // global stack dec for desc order ele of bst 

TreeNode*getSmall(){
    if(asc.empty()){
        // agar stack khali hai 
        return nullptr;
    }
    TreeNode*small=asc.top();                      // sbse chotta wla ele stack k top par hi rhega 
    asc.pop();       

    TreeNode* rightchild=small->right;             // dekhlo ki koi righchild hai kya small wley node ka 
    while(rightchild){
        // jab tak wo child hai 
        asc.push(rightchild);                     // right child ko stack mein dal lo 
        rightchild=rightchild->left;         // rightchild k sath purey left wley uskey khandan ko bhi dal lo
    }
    return small;
}

TreeNode* getBig(){
    if(desc.empty()){
        // agar desc wla Stack Empty hua 
        return nullptr;
    }
    TreeNode* big=desc.top();                        // stack ka sabse bda ele stack k top par rahega 
    desc.pop();

    TreeNode* leftchild=big->left;                   // dekhlo ki koi left child hai kya big node ka 
    while(leftchild){
        // jab tak wo child hai 
        desc.push(leftchild);                        // rightchild ko stack mei dal lo 
        leftchild=leftchild->right;                // khandan sath mein chlega 
    }
    return big;
}

    bool findTarget(TreeNode* root, int k) {
        // agar tree ka root hi null hai toh tree hi nhi hai 
        if(root==nullptr){
            return false;
        }

        TreeNode*t=root;                     // root se hi start hoga 
        while(t){
            asc.push(t);                     // root ko hi push kardo 
            t=t->left;                      // purey left ko push kartey rho jab tak left null nhi hojata 
        }

        t=root;                                    // root se wapis restart karo 
        while(t){
            desc.push(t);                            // root ko dalo stack mei
            t=t->right;                              // purey right ko push krtey rho till right not be null
        }

        TreeNode*i=getSmall();                // usi stack mein i shuru ka ptr bnega 
        TreeNode*j=getBig();                  // usi stack mei j last wley ele ka ptr bnega 

        while(i && j && i!=j && i->val<=j->val){
            // jab tak i and j node hold ho i not equal to j h and i ka value j se km ho 
            int sum=i->val+j->val;             // add kro dono k value ko
            
            if(sum==k){
                return true;
            }
            else if(sum>k){
                j=getBig();
            }
            else{
                i=getSmall();
            }
        }
        return false;                       // agar hold nhi hua dono cases mein else if and else mei 
    } 
};