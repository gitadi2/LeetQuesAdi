class Solution {
public:
    struct Node{
        int len;                    // Total length of this segment
        int left;                   // Starting character ki continuous length
        int right;                  // Ending character ki continuous length
        int best;                   // Is segment ka maximum same character length
        char lc;                    // Leftmost character
        char rc;                    // Rightmost character
    };

    vector<Node>tree;               // Segment Tree

    Node merge(Node a,Node b){

        Node c;

        c.len=a.len+b.len;

        c.lc=a.lc;
        c.rc=b.rc;

        c.left=a.left;
        c.right=b.right;

        c.best=max(a.best,b.best);

        // Agar left segment ka pura part same hai
        if(a.left==a.len && a.rc==b.lc){
            c.left=a.len+b.left;
        }

        // Agar right segment ka pura part same hai
        if(b.right==b.len && a.rc==b.lc){
            c.right=b.len+a.right;
        }

        // Dono segments ke beech ka same character
        if(a.rc==b.lc){
            c.best=max(c.best,a.right+b.left);
        }

        return c;
    }

    void build(string&s,int node,int low,int high){

        // Leaf node
        if(low==high){

            tree[node].len=1;
            tree[node].left=1;
            tree[node].right=1;
            tree[node].best=1;
            tree[node].lc=s[low];
            tree[node].rc=s[low];

            return;
        }

        int mid=(low+high)/2;

        // Left Subtree
        build(s,2*node,low,mid);

        // Right Subtree
        build(s,2*node+1,mid+1,high);

        // Dono ko merge kardo
        tree[node]=merge(tree[2*node],tree[2*node+1]);

        return;
    }

    void update(string&s,int node,int low,int high,int idx){

        // Leaf node par aa gye
        if(low==high){

            tree[node].lc=s[idx];
            tree[node].rc=s[idx];

            return;
        }

        int mid=(low+high)/2;

        // Jis index ko update karna hai us side jao
        if(idx<=mid){

            update(s,2*node,low,mid,idx);
        }
        else{

            update(s,2*node+1,mid+1,high,idx);
        }

        // Update ke baad parent ko dobara merge kardo
        tree[node]=merge(tree[2*node],tree[2*node+1]);

        return;
    }

    vector<int> longestRepeating(string s,string queryCharacters,vector<int>&queryIndices){

        int n=s.size();

        tree.resize(4*n);

        // Segment Tree build kardo
        build(s,1,0,n-1);

        vector<int>res;

        for(int i=0;i<queryCharacters.size();i++){

            int idx=queryIndices[i];

            // Character update kardo
            s[idx]=queryCharacters[i];

            // Segment Tree mei bhi update kardo
            update(s,1,0,n-1,idx);

            // Root par pura string ka answer hoga
            res.push_back(tree[1].best);
        }

        return res;
    }
};