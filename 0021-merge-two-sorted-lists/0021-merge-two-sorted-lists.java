/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

    public ListNode mergeTwoLists(ListNode l1,ListNode l2){

        // dummy node bana lo
        ListNode d=new ListNode(-1);

        // current pointer
        ListNode c=d;

        // jab tak dono lists mei elements hai
        while(l1!=null && l2!=null){

            // agar pehli list ka element chota hai
            if(l1.val<=l2.val){

                c.next=l1;
                l1=l1.next;
            }

            // warna dusri list ka element jodo
            else{

                c.next=l2;
                l2=l2.next;
            }

            // current ko aage badha do
            c=c.next;
        }

        // agar pehli list bachi hai
        if(l1!=null){
            c.next=l1;
        }

        // agar dusri list bachi hai
        if(l2!=null){
            c.next=l2;
        }

        // merged list return kardo
        return d.next;
    }
}