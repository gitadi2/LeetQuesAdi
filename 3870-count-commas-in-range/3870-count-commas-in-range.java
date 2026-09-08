class Solution {
    public int countCommas(int n) {
        // Agar n 1000 se chhota hai toh koi comma nahi hai
        if(n<1000){
            return 0;
        }

        // 1000 se n tak har number mein 1 comma hai
        int res=n-999;

        return res;
    }
}