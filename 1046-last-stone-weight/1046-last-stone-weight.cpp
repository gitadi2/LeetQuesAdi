class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int> pq;     // Max Heap Dec

        // Inserting all the Stones into the Heap
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        
        // Jab tak heap mein atmost 1 stone h (yani 1 se zyda)
        while(pq.size()>1){
            int first=pq.top();          //Largest Stone 
            pq.pop();

            int second=pq.top();         //Second Largest Stone 
            pq.pop();

            if(first==second){
                // Stones are destroyed 
                continue;
            }
            // New Wt= y-x
            pq.push(first-second);
        }

        // Agar heap empty hai 
        if(pq.empty()){
            return 0;
        }

        return pq.top();          // The last rem stone 
    }
};