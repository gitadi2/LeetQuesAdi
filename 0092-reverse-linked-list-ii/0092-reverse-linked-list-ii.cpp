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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr){
            // if the LInked List is Empty
            return nullptr;
        }

        if(left==right){
            // only 1 node will be reversed so it doesnt worth it
            return head;
        }

        // Main Program 
        ListNode* t=head;                    //Temp Variable for Traversal
        ListNode* before=nullptr;               // before Node of the curr
        int pos=1;                           // Traversal Starts from the position 1st of the LL

        while(t!=nullptr){
            if(pos<left){
                // If the Traversal havent yet reached the left posn.
                before=t;
                t=t->next;
                pos++;
                continue;
            }

            // Position has Reached the Left; then reverse the times is done
            ListNode* curr=t;
            ListNode* prev=nullptr;
            int times=right-left+1;

            while(times--){
                // Till the Times it being held up 
                ListNode* nex=curr->next;
                curr->next=prev;

                prev=curr;
                curr=nex;
            }

            t->next=curr;

            if(before){
                before->next=prev;
                return head;
            }
            return prev;
        }
        return head;
    }
};