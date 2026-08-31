/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */
var nodesBetweenCriticalPoints=function(head){
    let ans=[-1,-1]; // minimum aur maximum distance store karne ke liye

    if(head===null||head.next===null||head.next.next===null){
        return ans; // agar critical point possible hi nahi hai
    }

    let prev=head; // previous node ko track kar lo
    let curr=head.next; // current node ko track kar lo
    let next=curr.next; // next node ko track kar lo

    let first=-1; // first critical point ki position
    let last=-1; // last critical point ki position
    let mn=Infinity; // minimum distance store karenge
    let pos=1; // current node ki position

    while(next!==null){
        if((curr.val>prev.val&&curr.val>next.val)||(curr.val<prev.val&&curr.val<next.val)){

            if(first===-1){
                first=pos; // first critical point store kar do
            }

            if(last!==-1){
                mn=Math.min(mn,pos-last); // minimum distance update kar do
            }

            last=pos; // latest critical point update kar do
        }

        prev=curr; // previous node ko aage move karo
        curr=next; // current node ko aage move karo
        next=next.next; // next node ko aage move karo
        pos++; // position badha do
    }

    if(first===-1||first===last){
        return ans; // agar 2 critical points nahi mile
    }

    ans[0]=mn; // minimum distance store kar do
    ans[1]=last-first; // maximum distance store kar do

    return ans; // final answer return kar do
};