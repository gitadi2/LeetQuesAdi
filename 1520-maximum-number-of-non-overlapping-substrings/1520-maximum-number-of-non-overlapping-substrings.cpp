// By Greedy + Interval Method

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();

        // Har character ka first aur last occurrence store karo
        vector<int>first(26,n);
        vector<int>last(26,-1);

        for(int i=0;i<n;i++){
            int x=s[i]-'a';
            first[x]=min(first[x],i);
            last[x]=i;
        }
        vector<pair<int,int>>v;

        // Har character ke liye valid interval find karo
        for(int i=0;i<n;i++){
            int x=s[i]-'a';
            // Sirf character ki first occurrence se interval start karo
            if(first[x]!=i){
                continue;
            }
            int l=i;
            int r=last[x];
            bool flag=true;

            for(int j=l;j<=r;j++){
                int y=s[j]-'a';

                // Agar koi character interval ke bahar start hota hai toh current interval valid nahi hai
                if(first[y]<l){
                    flag=false;
                    break;
                }
                // Interval ko extend karo
                r=max(r,last[y]);
            }
            if(flag){
                v.push_back({l,r});
            }
        }
        // Ending point ke according sort karo
        sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b){
            return a.second<b.second;
        });

        vector<string>res;
        int prev=-1;

        // Non-overlapping intervals choose karo
        for(int i=0;i<v.size();i++){
            int l=v[i].first;
            int r=v[i].second;

            if(l>prev){
                res.push_back(s.substr(l,r-l+1));
                prev=r;
            }
        }
        return res;
    }
};