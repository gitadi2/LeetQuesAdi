/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func nodesBetweenCriticalPoints(head *ListNode) []int {
	ans := []int{-1, -1} // minimum aur maximum distance store karne ke liye

	if head == nil || head.Next == nil || head.Next.Next == nil {
		return ans // agar critical point possible hi nahi hai
	}

	prev := head // previous node ko track kar lo
	curr := head.Next // current node ko track kar lo
	next := curr.Next // next node ko track kar lo

	first := -1 // first critical point ki position
	last := -1 // last critical point ki position
	mn := int(^uint(0) >> 1) // minimum distance store karenge
	pos := 1 // current node ki position

	for next != nil {
		if (curr.Val > prev.Val && curr.Val > next.Val) ||
			(curr.Val < prev.Val && curr.Val < next.Val) {

			if first == -1 {
				first = pos // first critical point store kar do
			}

			if last != -1 && pos-last < mn {
				mn = pos - last // minimum distance update kar do
			}

			last = pos // latest critical point update kar do
		}

		prev = curr // previous node ko aage move karo
		curr = next // current node ko aage move karo
		next = next.Next // next node ko aage move karo
		pos++ // position badha do
	}

	if first == -1 || first == last {
		return ans // agar 2 critical points nahi mile
	}

	ans[0] = mn // minimum distance store kar do
	ans[1] = last - first // maximum distance store kar do

	return ans // final answer return kar do
}