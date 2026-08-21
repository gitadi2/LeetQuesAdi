class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n=coins.size();
        // lcm nikalne ke liye gcd ka use karenge
        auto lcm=[&](long long a,long long b){
            return a/__gcd(a,b)*b;
        };
        // kisi amount x tak kitne amounts ban sakte hain
        auto count=[&](long long x){
            long long ans=0;
            // inclusion-exclusion
            for(int mask=1;mask<(1<<n);mask++){
                long long cur=1;
                int bits=0;
                bool ok=true;

                for(int i=0;i<n;i++){
                    if(mask&(1<<i)){
                        bits++;

                        cur=lcm(cur,coins[i]);

                        // agar lcm x se bada ho gaya
                        if(cur>x){
                            ok=false;
                            break;
                        }
                    }
                }
                if(!ok) continue;

                if(bits%2==1)
                    ans+=x/cur;
                else
                    ans-=x/cur;
            }
            return ans;
        };
        // binary search
        long long l=1;
        long long r=1LL*k*(*min_element(coins.begin(),coins.end()));

        while(l<r){
            long long mid=l+(r-l)/2;

            // agar mid tak k ya usse zyada amounts hain
            // to answer left side me hoga
            if(count(mid)>=k)
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};