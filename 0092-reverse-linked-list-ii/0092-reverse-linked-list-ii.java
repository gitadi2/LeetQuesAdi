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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if(head==null){
            return null;
        }

        if(left==right){
            return head;
        }

        // Main prog
        ListNode t=head;
        ListNode before=null;
        int pos=1;

        while(t!=null){
            if(pos<left){
                before=t;
                t=t.next;
                pos++;
                continue;
            }

            ListNode curr=t;
            ListNode prev=null;
            int times=right-left+1;

            while(times-->0){
                ListNode nex=curr.next;
                curr.next=prev;

                prev=curr;
                curr=nex;
            }

            t.next=curr;

            if(before!=null){
                before.next=prev;
                return head;
            }
            return prev;
        }
        return head;
    }
}