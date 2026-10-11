class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start ^ goal;         // ans variable mein OR se leloo 
        int cnt=0;         // Intoit kardo count ko 
        for(int i=0;i<32;i++){
            // Check if the kth Bit is 1 
            if(ans & (1<<i)){
                cnt++;             // Agr ith bit 1 hua toh cnt badha do 
            }
        }
        return cnt; 
    }
};