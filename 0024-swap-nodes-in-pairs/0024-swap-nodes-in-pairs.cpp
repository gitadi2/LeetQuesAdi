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
void reverse(ListNode* head, int times){
    ListNode* curr=head;
    ListNode* prev=nullptr;
    while(times--){
        ListNode* nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return;
}

    ListNode* swapPairs(ListNode* head) {
        int size=2;                    // For the Pairs
        if(head==nullptr){
            // LL is empty
            return nullptr;
        }
        
        // Main Program
        ListNode* left=head;
        ListNode* right;
        ListNode* prevLeft=nullptr;              // The Left of the Previous Node in consideration
        ListNode* res=nullptr;                   // The Resultant Reverse paired Adj form of LL

        while(true){
            right=left;                         // Intialize Right and Left as same 
            for(int i=0;i<size-1;i++){
                // For incrementing Right Pairwaise
                if(right==nullptr){
                    // If there is No Right 
                    break;
                }
                right=right->next;              // Next of the Current value of the left 
            }

            if(right){
                // Left Right Pair is being traken into consideration 
                ListNode* nextLeft=right->next;    // For the left 2 ones and others 
                reverse(left,size);                // Reversing the connection of the Pair by 2 times
                if(prevLeft){
                    prevLeft->next=right;          // Prev left make conn with the Current Right
                }
                prevLeft=left;                     // The Current left then takes the Prev left value
                if(res==nullptr){
                    res=right;
                }
                left=nextLeft;
            }

            else{
                // Every Case Is being Touched
                if(prevLeft){
                    prevLeft->next=left;
                }
                if(res==nullptr){
                    res=left;
                }
                break;
            }
        }
        return res;
    }
};