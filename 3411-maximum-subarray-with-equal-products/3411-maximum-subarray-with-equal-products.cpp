class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long gcdVal = 0;
            long long lcmVal = 1;

            for (int j=i;j<n;j++) {
                prod*=nums[j];
                gcdVal=gcd(gcdVal, (long long)nums[j]);
                lcmVal=lcm(lcmVal, (long long)nums[j]);

                if (prod == gcdVal * lcmVal) {
                    ans = max(ans, j - i + 1);
                }

                // Maximum possible GCD * LCM is 25200.
                if (prod>25200) {
                    break;
                }
            }
        }
        return ans;
    }
};
