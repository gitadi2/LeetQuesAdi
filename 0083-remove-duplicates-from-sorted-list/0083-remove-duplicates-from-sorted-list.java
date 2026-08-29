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
class Solution{
    public ListNode deleteDuplicates(ListNode head){
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