class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();

        // Pair Bna Lo : value and original index
        vector<pair<int,int>>v;

        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }

        // Value ke according sort kardo
        sort(v.begin(),v.end());

        // Resultant Array
        vector<int>res(n);

        int i=0;

        while(i<n){
            int j=i;

            // Ek Group bna lo
            while(j+1<n && v[j+1].first-v[j].first<=limit){
                j++;
            }

            // Current Group ke indexes store karo
            vector<int>index;

            for(int k=i;k<=j;k++){
                index.push_back(v[k].second);
            }
            // Original indexes ko sort kardo
            sort(index.begin(),index.end());
            // Sorted values ko sorted indexes par daal do
            for(int k=0;k<index.size();k++){
                res[index[k]]=v[i+k].first;
            }
            // Next Group par jao
            i=j+1;
        }
        return res;
    }
};