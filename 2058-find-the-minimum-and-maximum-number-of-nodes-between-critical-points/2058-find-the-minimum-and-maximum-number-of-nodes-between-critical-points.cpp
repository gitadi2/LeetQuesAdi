/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head){
        vector<int>ans={-1,-1}; // minimum aur maximum distance store karne ke liye

        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return ans; // agar critical point possible hi nahi hai
        }

        ListNode*prev=head; // previous node ko track kar lo
        ListNode*curr=head->next; // current node ko track kar lo
        ListNode*next=curr->next; // next node ko track kar lo

        int first=-1; // first critical point ka position
        int last=-1; // last critical point ka position
        int mn=INT_MAX; // minimum distance store karenge
        int pos=1; // current node ki position

        while(next!=NULL){
            if((curr->val>prev->val && curr->val>next->val) || (curr->val<prev->val && curr->val<next->val)){
                if(first==-1){
                    first=pos; // first critical point ka position store kar do
                }
                if(last!=-1){
                    mn=min(mn,pos-last); // consecutive critical points ka minimum distance nikal lo
                }
                last=pos; // latest critical point update kar do
            }
            prev=curr; // previous ko aage move karo
            curr=next; // current ko aage move karo
            next=next->next; // next ko aage move karo
            pos++; // position badha do
        }
        if(first==-1 || first==last){
            return ans; // agar 2 critical points nahi mile
        }
        ans[0]=mn; // minimum distance store kar do
        ans[1]=last-first; // first aur last critical point ka maximum distance

        return ans; // final answer return kar do
    }
};