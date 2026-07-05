class Solution {
    public long fun(int[] piles,int n,int k){
        long h=0;
        for(int i=0;i<n;i++){
            h=h+piles[i]/k;
            if(piles[i]%k!=0){
                h++;
            }
        }
        return h;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int n=piles.length;
        int low=1;
        int high=0;
        for(int i=0;i<n;i++){
            high=Math.max(high,piles[i]);
        }

        int res=-1;

        while(low<=high){
            int k=(low+high)/2;

            long hour=fun(piles,n,k);

            if(hour>h){
                low=k+1;
            }
            else{
                res=k;
                high=k-1;
            }
        }
        return res;
    }
}