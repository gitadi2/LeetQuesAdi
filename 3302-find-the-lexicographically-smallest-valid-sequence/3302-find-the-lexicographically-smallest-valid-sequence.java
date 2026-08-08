class Solution {
    public int[] validSequence(String word1,String word2) {
        int n=word1.length();
        int m=word2.length();

        int[] dp=new int[n+1];

        int j=m-1;

        // Peechey se matching check kardo
        for(int i=n-1;i>=0;i--){
            if(j>=0 && word1.charAt(i)==word2.charAt(j)){
                dp[i]=dp[i+1]+1;
                j--;
            }
            else{
                dp[i]=dp[i+1];
            }
        }

        int[] ans=new int[m];

        int i=0;
        j=0;

        // Lexicographically smallest index lene ki koshish karo
        while(i<n && j<m){
            if(word1.charAt(i)==word2.charAt(j)){
                // Same character hai toh seedha lelo
                ans[j]=i;
                j++;
            }
            else{
                // Ek mismatch allowed hai
                if(dp[i+1]>=m-1-j){
                    // Current index ko mismatch ke liye use karlo
                    ans[j]=i;
                    j++;
                    i++;

                    break;
                }
            }
            i++;
        }

        // Agar word2 pura match nhi hua
        if(j<m && i==n){
            return new int[0];
        }

        // Bacha hua part exact match karo
        while(j<m && i<n){
            if(word1.charAt(i)==word2.charAt(j)){
                ans[j]=i;
                j++;
            }
            i++;
        }
        // Agar pura word2 match nhi hua
        if(j<m){
            return new int[0];
        }
        return ans;
    }
}