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
    public int[] nodesBetweenCriticalPoints(ListNode head){
        int[] ans={-1,-1}; // minimum aur maximum distance store karne ke liye

        if(head==null||head.next==null||head.next.next==null){
            return ans; // agar critical point possible hi nahi hai
        }

        ListNode prev=head; // previous node ko track kar lo
        ListNode curr=head.next; // current node ko track kar lo
        ListNode next=curr.next; // next node ko track kar lo

        int first=-1; // first critical point ki position
        int last=-1; // last critical point ki position
        int mn=Integer.MAX_VALUE; // minimum distance store karenge
        int pos=1; // current node ki position

        while(next!=null){
            if((curr.val>prev.val&&curr.val>next.val)||(curr.val<prev.val&&curr.val<next.val)){

                if(first==-1){
                    first=pos; // first critical point store kar do
                }

                if(last!=-1){
                    mn=Math.min(mn,pos-last); // minimum distance update kar do
                }

                last=pos; // latest critical point update kar do
            }

            prev=curr; // previous node ko aage move karo
            curr=next; // current node ko aage move karo
            next=next.next; // next node ko aage move karo
            pos++; // position badha do
        }

        if(first==-1||first==last){
            return ans; // agar 2 critical points nahi mile
        }

        ans[0]=mn; // minimum distance store kar do
        ans[1]=last-first; // maximum distance store kar do

        return ans; // final answer return kar do
    }
}