class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();

        vector<int>a(n+1);
        for(int i=0;i<n;i++){
            a[i]=nums[i]+1;
        }
        a[n]=0;

        int N=n+1;
        vector<int>p(N),c(N);

        // Initial sorting
        vector<int>cnt(max(N,100002),0);

        for(int i=0;i<N;i++){
            cnt[a[i]]++;
        }
        for(int i=1;i<cnt.size();i++){
            cnt[i]+=cnt[i-1];
        }
        for(int i=N-1;i>=0;i--){
            p[--cnt[a[i]]]=i;
        }
        c[p[0]]=0;
        int classes=1;

        for(int i=1;i<N;i++){
            if(a[p[i]]!=a[p[i-1]]){
                classes++;
            }
            c[p[i]]=classes-1;
        }

        // Build Suffix Array using doubling
        vector<int>pn(N),cn(N);

        for(int len=1;len<N;len*=2){
            for(int i=0;i<N;i++){
                pn[i]=p[i]-len;
                if(pn[i]<0){
                    pn[i]+=N;
                }
            }
            fill(cnt.begin(),cnt.begin()+classes,0);

            for(int i=0;i<N;i++){
                cnt[c[pn[i]]]++;
            }
            for(int i=1;i<classes;i++){
                cnt[i]+=cnt[i-1];
            }
            for(int i=N-1;i>=0;i--){
                p[--cnt[c[pn[i]]]]=pn[i];
            }

            cn[p[0]]=0;
            int newClasses=1;

            for(int i=1;i<N;i++){
                pair<int,int>cur={c[p[i]],c[(p[i]+len)%N]};
                pair<int,int>prev={c[p[i-1]],c[(p[i-1]+len)%N]};

                if(cur!=prev){
                    newClasses++;
                }

                cn[p[i]]=newClasses-1;
            }
            c.swap(cn);
            classes=newClasses;

            if(classes==N){
                break;
            }
        }

        // Remove the suffix containing only the sentinel
        vector<int>sa;

        for(int i=1;i<N;i++){
            sa.push_back(p[i]);
        }

        // Build LCP array using Kasai Algorithm
        vector<int>rank(n);
        for(int i=0;i<n;i++){
            rank[sa[i]]=i;
        }

        vector<int>lcp(n,0);
        int h=0;

        for(int i=0;i<n;i++){
            int r=rank[i];

            if(r==0){
                continue;
            }

            int j=sa[r-1];

            while(i+h<n && j+h<n && nums[i+h]==nums[j+h]){
                h++;
            }

            lcp[r]=h;

            if(h>0){
                h--;
            }
        }

        // Find the minimum unique subarray length
        int res=n;

        for(int i=0;i<n;i++){
            int r=rank[i];

            int maxi=0;

            if(r>0){
                maxi=max(maxi,lcp[r]);
            }

            if(r<n-1){
                maxi=max(maxi,lcp[r+1]);
            }

            if(maxi<n-i){
                res=min(res,maxi+1);
            }
        }
        return res;
    }
};