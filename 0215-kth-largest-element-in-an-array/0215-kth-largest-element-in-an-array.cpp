class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;    // Min heap bna loo
        int i;

        for(i=0;i<k;i++){
            pq.push(nums[i]);            // k mein jo jo elements hai utney gino and push kardo 
        }

        for(i=k;i<n;i++){
            // Agey ke lelements screen karna hai 
            if(nums[i]<=pq.top()){
                continue;
            }
            // agar upar wla condition ke ulta hai 
            pq.pop();                 // Pop Kardo 
            pq.push(nums[i]);           // ab finally push kardo 
        }
        return pq.top();          // Final ans mil jaega 
    }
};