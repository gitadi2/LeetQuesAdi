class Solution {

    public int mySqrt(int x) {

        // agar x 0 ya 1 hai
        if(x<=1){
            return x;
        }

        int l=1,h=x;
        int ans=0;

        // binary search chalao
        while(l<=h){

            int m=l+(h-l)/2;

            // agar square root mil gaya
            if(m==x/m){
                return m;
            }

            // agar square chota hai
            if(m<x/m){

                ans=m;
                l=m+1;
            }

            // warna left mei jao
            else{
                h=m-1;
            }
        }

        // answer return kardo
        return ans;
    }
}