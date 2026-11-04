// Sliding Window + Median + DP

class Solution {
public:
    multiset<int>low;
    multiset<int>high;

    long long lowSum=0;
    long long highSum=0;

    // Dono sets ko balance karo
    void balance(){
        int total=low.size()+high.size();
        int target=(total+1)/2;

        while(low.size()>target){
            int val=*low.rbegin();

            low.erase(prev(low.end()));
            lowSum-=val;

            high.insert(val);
            highSum+=val;
        }
        while(low.size()<target){
            int val=*high.begin();

            high.erase(high.begin());
            highSum-=val;

            low.insert(val);
            lowSum+=val;
        }
    }
    // Element add karo
    void add(int val){
        if(low.empty() || val<=*low.rbegin()){
            low.insert(val);
            lowSum+=val;
        }
        else{
            high.insert(val);
            highSum+=val;
        }

        balance();
    }

    // Element remove karo
    void remove(int val){
        if(low.find(val)!=low.end()){
            low.erase(low.find(val));
            lowSum-=val;
        }
        else{
            high.erase(high.find(val));
            highSum-=val;
        }
        balance();
    }
    // Current window ka minimum cost find karo
    long long getCost(){
        long long median=*low.rbegin();

        long long left=median*low.size()-lowSum;
        long long right=highSum-median*high.size();

        return left+right;
    }

    long long minOperations(vector<int>&nums,int x,int k){
        int n=nums.size();

        // Sliding Window Approach
        vector<long long>cost;

        for(int i=0;i<n;i++){
            // Window size x se bada hone par remove karo
            if(i>=x){
                remove(nums[i-x]);
            }

            // Current element add karo
            add(nums[i]);

            // Jab window size x ho jaye
            if(i>=x-1){
                cost.push_back(getCost());
            }
        }
        // DP Approach
        long long INF=LLONG_MAX/4;

        vector<long long>prev(n+1,0);
        vector<long long>curr(n+1,INF);

        for(int j=1;j<=k;j++){
            fill(curr.begin(),curr.end(),INF);

            for(int i=1;i<=n;i++){
                // Current position skip karo
                curr[i]=curr[i-1];

                // Current window select karo
                if(i>=x && prev[i-x]!=INF){
                    curr[i]=min(
                        curr[i],
                        prev[i-x]+cost[i-x]
                    );
                }
            }
            prev=curr;
        }
        return prev[n];
    }
};