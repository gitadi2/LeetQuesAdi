/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution{
    public ListNode DeleteDuplicates(ListNode head){
        ListNode curr=head; // current node ko track kar lo

        while(curr!=null&&curr.next!=null){
            if(curr.val==curr.next.val){
                curr.next=curr.next.next; // duplicate node ko skip kar do
            }
            else{
                curr=curr.next; // next node par chale jao
            }
        }
        return head; // updated linked list return kar do
    }
}