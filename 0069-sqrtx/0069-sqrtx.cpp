class Solution {
public:

    int mySqrt(int x){

        // agar x 0 ya 1 hai
        if(x<=1){
            return x;
        }

        long long l=1,h=x;
        int ans=0;

        // binary search chalao
        while(l<=h){

            long long m=l+(h-l)/2;

            // agar square equal hai
            if(m*m==x){
                return m;
            }

            // agar square chota hai
            if(m*m<x){

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
};