// Using the Bitwise Operators 

class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;               // Shuru mein 1 cnt variable lelo 
        while(n>1){
            if(n & 1) cnt++;     // Agr odd hai toh 1 aaega so cnt ko badha do ... n&1 means n%2==0
            n=n>>1;               // Wapis next div karo jab tak ki 1 na bachey ... n>>1 means n=n/2
        }
        if(n==1) cnt++;          // Jab 1 bach jaye toh cnt mein ek jodo and end karo 

        return cnt;              // Final cnt ko return kardo 
    }
};