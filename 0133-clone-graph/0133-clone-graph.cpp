/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/*
// Definition for a Node.
class Node{
public:
    int val;
    vector<Node*>neighbors;

    Node(){
        val=0;
        neighbors={};
    }

    Node(int _val){
        val=_val;
        neighbors={};
    }

    Node(int _val,vector<Node*>_neighbors){
        val=_val;
        neighbors=_neighbors;
    }
};
*/
class Solution{
public:
    unordered_map<Node*,Node*>mp; // original node aur cloned node ka mapping store karo

    Node* dfs(Node* node){
        if(node==NULL){
            return NULL; // agar node null hai to null return karo
        }
        if(mp.find(node)!=mp.end()){
            return mp[node]; // agar node pehle clone ho chuka hai to wahi return karo
        }

        Node* copy=new Node(node->val); // current node ka clone bana do
        mp[node]=copy; // original aur clone ka mapping store kar do

        for(Node* nei:node->neighbors){
            copy->neighbors.push_back(dfs(nei)); // neighbour ko clone karke add kar do
        }
        return copy; // cloned node return kar do
    }

    Node* cloneGraph(Node* node){
        return dfs(node); // DFS se complete graph clone kar do
    }
};