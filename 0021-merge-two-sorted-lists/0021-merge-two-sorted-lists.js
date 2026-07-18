/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists=function(l1,l2){

    // dummy node bana lo
    let d=new ListNode(-1);

    // current pointer
    let c=d;

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
};