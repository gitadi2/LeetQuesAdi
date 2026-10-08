class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        while(n!=0){
            n=n&(n-1);          // RightMost set Bit ko Remove kardo 
            cnt++;              // 1 set bit Remove hogya 
        }
        return cnt;
    }
};