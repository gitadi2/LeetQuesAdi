// Sliding Window + Monotonic Dequeue

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();

        deque<pair<int,int>>dq;

        long long cost=0;
        long long res=0;
        int j=n-1;

        for(int i=n-1;i>=0;i--){
            int cnt=1;
            // Merge smaller elements into the current value
            while(!dq.empty() && dq.back().first<nums[i]){
                int val=dq.back().first;
                int c=dq.back().second;

                cost+=1LL*(nums[i]-val)*c;

                cnt+=c;
                dq.pop_back();
            }
            dq.push_back({nums[i],cnt});

            // Shrink the window if cost exceeds k
            while(cost>k){
                int val=dq.front().first;
                int c=dq.front().second;

                dq.pop_front();

                cost-=val-nums[j];
                j--;

                if(c>1){
                    dq.push_front({val,c-1});
                }
            }
            res+=j-i+1;
        }
        return res;
    }
};