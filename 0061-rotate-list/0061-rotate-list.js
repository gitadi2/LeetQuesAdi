/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function(head, k) {
    if(head==null){
        return null;
    }

    let last=head;
    let n=1;

    while(last.next!=null){
        n++;
        last=last.next;
    }

    k=k%n;
    if(k==0){
        return head;
    }

    let t=head;
    let count=1;
    let c=n-k;
    while(t!=null){
        if(count==c){
            break;
        }
        count++;
        t=t.next;
    }

    last.next=head;
    let res=t.next;
    t.next=null;

    return res;
};