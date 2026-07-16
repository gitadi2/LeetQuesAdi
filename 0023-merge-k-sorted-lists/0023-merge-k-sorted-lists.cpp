/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
class Node{
    public:
        ListNode* node;
           
        //Constructor
        Node(ListNode* n){
            node=n;
        }
};

struct cmp{
    bool operator()(const Node& a, const Node & b){
        return a.node->val>b.node->val;         // Min Heap of the Values of the LL
    }
};

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();

        //Heap bna loo
        priority_queue<Node,vector<Node>,cmp> pq;

        for(int i=0;i<n;i++){
            if(lists[i]!=nullptr){
                pq.push(Node(lists[i]));
            }
        }

        // Resultant LL bna lo 
        ListNode* res=new ListNode(-1);

        //Currenet Pointer 
        ListNode* temp=res;

        while(!pq.empty()){
            Node curr=pq.top();          // Top wla LL ka Node dekj]ho
            pq.pop();                    //Top kio hi popo kardo 

            //Resultant mei Node Add kardo 
            temp->next=curr.node;
            temp=temp->next;

            if(curr.node->next!=nullptr){
                pq.push(Node(curr.node->next));
            }
        }
        return res->next;
    }
};