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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;                   // Taking the head as the current intially
        ListNode* prev=nullptr;                   // Taking the previous as null intially

        while(curr!=nullptr){
            ListNode* nex=curr->next;          // Next Node of the current is being stored first
            curr->next=prev;                   // The next connection is Reversed to the previous

            prev=curr;                         // Previous is moved by 1
            curr=nex;                          // Current is also moved by 1
        }
        return prev;                           // The Final reversed Linked List through the Head 
    }
};