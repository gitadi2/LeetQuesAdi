class Solution {
public:
    const long long LIM = 1000001;

    long long nCr(int n,int r){
        if(r>n) return 0;
        r=min(r,n-r);
        long long ans=1;
        for(int i=1;i<=r;i++){
            ans=ans*(n-i+1)/i;
            if(ans>=LIM) return LIM;
        }
        return ans;
    }

    long long cnt(vector<int>&f){
        int tot=0;
        for(int x:f) tot+=x;

        long long ans=1;
        for(int x:f){
            ans*=nCr(tot,x);
            if(ans>=LIM) return LIM;
            tot-=x;
        }
        return ans;
    }

    string smallestPalindrome(string s,int k) {
        vector<int> f(26,0);

        for(char c:s) f[c-'a']++;

        string mid="";
        vector<int> h(26);

        for(int i=0;i<26;i++){
            if(f[i]&1) mid.push_back(char('a'+i));
            h[i]=f[i]/2;
        }

        if(cnt(h)<k) return "";

        string left="";

        int len=s.size()/2;

        while((int)left.size()<len){
            for(int i=0;i<26;i++){
                if(h[i]==0) continue;

                h[i]--;

                long long ways=cnt(h);

                if(ways>=k){
                    left.push_back(char('a'+i));
                    break;
                }

                k-=ways;
                h[i]++;
            }
        }

        string right=left;
        reverse(right.begin(),right.end());

        return left+mid+right;
    }
};