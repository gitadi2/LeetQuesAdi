/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates=function(head){
    let curr=head; // current node ko track kar lo

    while(curr!==null&&curr.next!==null){
        if(curr.val===curr.next.val){
            curr.next=curr.next.next; // duplicate node ko skip kar do
        }
        else{
            curr=curr.next; // next node par chale jao
        }
    }

    return head; // updated linked list return kar do
};