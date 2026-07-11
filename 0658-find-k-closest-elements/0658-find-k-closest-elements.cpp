class Solution {
public:
struct cmp{
    bool operator()(const pair<int,int>&a,const pair<int,int>&b){
        if(a.first!=b.first){
            // Max wala hi lena hoga 
            return b.first>a.first;
        }
        // Second wla bhi max hii lenna hoga 
        return b.second>a.second;
    }
};

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();

        // Priority Queue Declaration 
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;

        for(int i=0;i<n;i++){
            int element=arr[i];

            int dist=abs(element-x);         // Absolute wla distance lelia jaega 

            pair<int,int> curr={dist,element};    // Store like This 

            if(pq.size()<k){
                // Still in the Process ; toh randomly push k elements and move fwd
                pq.push(curr);
                continue;
            }

            if(curr.first>pq.top().first){
                // Skip kro agey badho 
                continue;
            }

            if(curr.first==pq.top().first && curr.second>=pq.top().second){
                // Skip and move fwd
                continue;
            }
            pq.pop();          //Ofc the Top of the Heap gets poped
            pq.push(curr);      // pusgh the Current Element
        }

        vector<int> res;

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        sort(res.begin(),res.end());         // The Resulatant array has to be in the Sorted Form 

        return res;                           // Final sorted resultant array 
    }
};