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

    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){

        // dummy node bana lo
        ListNode* d=new ListNode(-1);

        // current pointer
        ListNode* c=d;

        // jab tak dono lists mei elements hai
        while(l1!=nullptr && l2!=nullptr){

            // agar pehli list ka element chota hai
            if(l1->val<=l2->val){

                c->next=l1;
                l1=l1->next;
            }

            // warna dusri list ka element jodo
            else{

                c->next=l2;
                l2=l2->next;
            }

            // current ko aage badha do
            c=c->next;
        }

        // agar pehli list bachi hai
        if(l1!=nullptr){
            c->next=l1;
        }

        // agar dusri list bachi hai
        if(l2!=nullptr){
            c->next=l2;
        }

        // merged list return kardo
        return d->next;
    }
};