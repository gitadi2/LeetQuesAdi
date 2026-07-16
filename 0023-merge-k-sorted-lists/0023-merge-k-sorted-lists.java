/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
class Solution {

    class Node{
        ListNode node;

        // Constructor
        Node(ListNode n){
            node=n;
        }
    }

    class cmp implements Comparator<Node>{
        public int compare(Node a,Node b){
            return a.node.val-b.node.val;      // Min Heap of the Values of the LL
        }
    }

    public ListNode mergeKLists(ListNode[] lists) {

        int n=lists.length;

        // Heap bna loo
        PriorityQueue<Node> pq=new PriorityQueue<>(new cmp());

        for(int i=0;i<n;i++){
            if(lists[i]!=null){
                pq.add(new Node(lists[i]));
            }
        }

        // Resultant LL bna lo
        ListNode res=new ListNode(-1);

        // Current Pointer
        ListNode temp=res;

        while(!pq.isEmpty()){

            Node curr=pq.poll();          // Top wla LL ka Node dekho

            // Resultant mei Node Add kardo
            temp.next=curr.node;
            temp=temp.next;

            if(curr.node.next!=null){
                pq.add(new Node(curr.node.next));
            }
        }

        return res.next;
    }
}