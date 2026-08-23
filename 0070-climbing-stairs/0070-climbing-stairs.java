class Solution {
    HashMap<Integer,Integer>dp=new HashMap<>();  // HashMap Bna Lo

    int fun(int i,int n){
        // Base Case 1: Agar Already hum last Stair par hai
        if(i==n){
            return 1;
        }
        // Base Case 2: Agar Already hum last Stair se agey hai
        if(i>n){
            return 0;                                 // As peechey nhi asktey
        }

        // Agar Ans already calc. hai .. yni ki Overlapping Subproblem
        if(dp.containsKey(i)){
            return dp.get(i);                         // Agar HashMap mei milgya toh return kardo
        }

        // Agar 1 step lia
        int a1=fun(i+1,n);

        // Agar 2 steps liye
        int a2=fun(i+2,n);

        int ans=a1+a2;

        // Store the Ans
        dp.put(i,ans);

        return ans;
    }

    public int climbStairs(int n){
        // Recursive Func. call kardo
        return fun(0,n);
    }
}