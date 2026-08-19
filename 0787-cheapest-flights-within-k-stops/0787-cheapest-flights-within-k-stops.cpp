class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>res(n,1e8);                // Resultant Array Bna lo shuru me sab inf 
        res[src]=0;                             // Src -. src ka res mei update karkey likho 0 hi aaega 

        // Relaxation Shuru kardo :for K+1 times karna 
        for(int i=0;i<k+1;i++){
            // k+1 times Relaxn karney se phe;leyt ek temp array of same res size ka bna lo 
            vector<int>temp=res;

            for(int j=0;j<flights.size();j++){
                int s=flights[j][0];                  // Source 
                int d=flights[j][1];                 // Destinatuion
                int p=flights[j][2];                 // Price 

                if(res[s]!=1e8 && temp[d]>res[s]+p){
                    // Agar inf nhi hai source wla and cond hold bhi hai , do the relaxn 
                    temp[d]=res[s]+p;
                }
            }
            // sab Honey k Baad res ko temp wley res se update karlo 
            res=temp;
        }
        if(res[dst]==1e8){
            return -1;
        }
        return res[dst];
    }
};