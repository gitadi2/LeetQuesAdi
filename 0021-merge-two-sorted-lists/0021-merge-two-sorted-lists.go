/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode,l2 *ListNode)*ListNode{

    // dummy node bana lo
    d:=&ListNode{Val:-1}

    // current pointer
    c:=d

    // jab tak dono lists mei elements hai
    for l1!=nil && l2!=nil{

        // agar pehli list ka element chota hai
        if l1.Val<=l2.Val{

            c.Next=l1
            l1=l1.Next

        }else{

            // warna dusri list ka element jodo
            c.Next=l2
            l2=l2.Next
        }

        // current ko aage badha do
        c=c.Next
    }

    // agar pehli list bachi hai
    if l1!=nil{
        c.Next=l1
    }

    // agar dusri list bachi hai
    if l2!=nil{
        c.Next=l2
    }

    // merged list return kardo
    return d.Next
}