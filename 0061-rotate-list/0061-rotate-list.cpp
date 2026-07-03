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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr){
            // There is no head of the LL
            return nullptr;
        }
        // For the nth node stuff
        ListNode* last=head;
        int n=1;                         // Head is Not Null so atleast 1 node will be there as initial

        while(last->next!=nullptr){
            n++;
            last=last->next;
        }

        k=k%n;
        if(k==0){
            return head;
        }

        // For the (n-k)th node stuff
        ListNode* t=head;            // Will see did we get n-k th node or not
        int count=1;
        int c=n-k;
        while(t!=nullptr){
            if(count==c){
                break;
            }
            count++;
            t=t->next;
        }
        last->next=head;
        ListNode* res=t->next;
        t->next=nullptr;

        return res;
    }
};