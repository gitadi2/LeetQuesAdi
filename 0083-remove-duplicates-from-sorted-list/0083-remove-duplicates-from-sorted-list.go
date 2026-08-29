/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	curr := head // current node ko track kar lo

	for curr != nil && curr.Next != nil {
		if curr.Val == curr.Next.Val {
			curr.Next = curr.Next.Next // duplicate node ko skip kar do
		} else {
			curr = curr.Next // next node par chale jao
		}
	}
	return head // updated linked list return kar do
}