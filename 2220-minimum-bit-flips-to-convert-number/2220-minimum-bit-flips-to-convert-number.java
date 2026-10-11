class Solution {
    public int minBitFlips(int start, int goal) {
        int ans=start ^ goal;
        int cnt=0;
        for(int i=0;i<32;i++){
            // Check if the ith Bit is set or not 
            if((ans & (1<<i))!=0){
                cnt++;          // if Set then cnt badha do 
            }
        }
        return cnt;
    }
}