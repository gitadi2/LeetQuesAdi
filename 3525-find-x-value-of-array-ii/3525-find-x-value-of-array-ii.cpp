class Solution {
public:
    struct Node{
        int prod;
        int cnt[5];
    };
    int k;
    vector<Node>tree;
    Node merge(Node&a,Node&b){
        Node res;
        res.prod=(a.prod*b.prod)%k;

        for(int i=0;i<k;i++){
            res.cnt[i]=a.cnt[i];
        }

        for(int i=0;i<k;i++){
            if(b.cnt[i]>0){
                int x=(a.prod*i)%k;
                res.cnt[x]+=b.cnt[i];
            }
        }

        return res;
    }

    void build(int node,int l,int r,vector<int>&nums){
        if(l==r){
            tree[node].prod=nums[l]%k;

            for(int i=0;i<k;i++){
                tree[node].cnt[i]=0;
            }

            tree[node].cnt[tree[node].prod]=1;
            return;
        }

        int mid=(l+r)/2;

        build(2*node,l,mid,nums);
        build(2*node+1,mid+1,r,nums);

        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }

    void update(int node,int l,int r,int idx,int val){
        if(l==r){
            tree[node].prod=val%k;

            for(int i=0;i<k;i++){
                tree[node].cnt[i]=0;
            }

            tree[node].cnt[tree[node].prod]=1;
            return;
        }

        int mid=(l+r)/2;

        if(idx<=mid){
            update(2*node,l,mid,idx,val);
        }
        else{
            update(2*node+1,mid+1,r,idx,val);
        }

        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }

    Node query(int node,int l,int r,int ql,int qr){
        if(ql<=l && r<=qr){
            return tree[node];
        }

        int mid=(l+r)/2;

        if(qr<=mid){
            return query(2*node,l,mid,ql,qr);
        }

        if(ql>mid){
            return query(2*node+1,mid+1,r,ql,qr);
        }

        Node left=query(2*node,l,mid,ql,qr);
        Node right=query(2*node+1,mid+1,r,ql,qr);

        return merge(left,right);
    }

    vector<int> resultArray(vector<int>&nums,int k,vector<vector<int>>&queries){
        this->k=k;

        int n=nums.size();

        tree.resize(4*n);

        build(1,0,n-1,nums);

        vector<int>res;

        for(int i=0;i<queries.size();i++){
            int index=queries[i][0];
            int value=queries[i][1];
            int start=queries[i][2];
            int x=queries[i][3];

            update(1,0,n-1,index,value);

            Node temp=query(1,0,n-1,start,n-1);

            res.push_back(temp.cnt[x]);
        }
        return res;
    }
};