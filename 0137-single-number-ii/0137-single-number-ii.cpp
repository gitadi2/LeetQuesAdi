// Better Soln (Using The Sorting Approach)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());              // Sort in the ascending order for the nums array
        // Traverse through the array from the index 1 
        for(int i=1;i<n;i=i+3){
            if(nums[i]!=nums[i-1]) return nums[i-1];   //...Agr curr prev equal nhi hai toh breakage hai
        }
        //..Agr continuity maintain hoti rahi 
        return nums[n-1];       // ...Last Element hi Single occurence wla ekle hai 
    }
};