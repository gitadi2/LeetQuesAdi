class Solution {
public:
    bool fun(vector<int>&bloomDay,int n,int m,int k,int guess){
        int flower=0;
        int bouquet=0;

        for(int i=0;i<n;i++){
            if(bloomDay[i]<=guess){
                flower++;
            }
            else{
                bouquet=bouquet+flower/k;
                flower=0;
            }
        }

        bouquet=bouquet+flower/k;

        if(bouquet>=m){
            return true;
        }
        else{
            return false;
        }
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();

        if((long long)m*k>n){
            return -1;
        }

        int low=INT_MAX;
        int high=INT_MIN;

        for(int i=0;i<n;i++){
            low=min(low,bloomDay[i]);
            high=max(high,bloomDay[i]);
        }

        int res=-1;

        while(low<=high){
            int guess=(low+high)/2;

            if(fun(bloomDay,n,m,k,guess)){
                res=guess;
                high=guess-1;
            }
            else{
                low=guess+1;
            }
        }

        return res;
    }
};