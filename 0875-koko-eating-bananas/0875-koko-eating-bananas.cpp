class Solution {
public:
long long fun(vector<int>&piles,int n,int k){
    long long h=0;
    for(int i=0;i<n;i++){
        h=h+piles[i]/k;
        if(piles[i]%k!=0){
            h++;
        }
    }
    return h;
}

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;                  // Min spedd 1 se shuru hoga
        int high=0;                 //Intially high ko zero maan lia
        for(int i=0;i<n;i++){
            high=max(high,piles[i]);      //Max speed max of the piles array m se lia jaega
        }

        int res=-1;                 // agar nhi hi kha payi ; to ye auto ans ho jaega 

        while(low<=high){
            int k=(low+high)/2;

            // Koko ko kitna time lagta hai khaney mein 
            long long hour=fun(piles,n,k);

            if(hour>h){
                // agar khaney ka tym guard ke aney k time se jyada hai; toh nhi kha paegi
                low=k+1;
            }
            else{
                // agar khaney ka tym guard ke aney k tym se kaam hai; toh kaha legi 
                res=k;        // par y min ho skta h ; tabhi store karlo
                high=k-1;
            }
        }
        return res; 
    }
};