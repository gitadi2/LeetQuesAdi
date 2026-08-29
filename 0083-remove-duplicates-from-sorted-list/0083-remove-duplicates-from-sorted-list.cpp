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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*curr=head; // current node ko track kar lo

        while(curr!=NULL&&curr->next!=NULL){
            if(curr->val==curr->next->val){
                curr->next=curr->next->next; // duplicate node ko skip kar do
            }
            else{
                curr=curr->next; // next node par chale jao
            }
        }
        return head; // updated linked list return kar do
    }
};