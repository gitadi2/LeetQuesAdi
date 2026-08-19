class Solution {
public:
    // Smallest cyclic rotation nikalna
    string fun(const string&s){
        int n=s.size();

        if(n<=1){
            return s;
        }

        string t=s+s;

        int i=0;
        int j=1;
        int k=0;

        while(i<n && j<n){
            k=0;

            while(k<n && t[i+k]==t[j+k]){
                k++;
            }

            if(k==n){
                break;
            }

            if(t[i+k]>t[j+k]){
                // i wala rotation bada hai
                i=i+k+1;

                if(i<=j){
                    i=j+1;
                }
            }
            else{
                // j wala rotation bada hai
                j=j+k+1;

                if(j<=i){
                    j=i+1;
                }
            }
        }
        int p=min(i,j);
        return t.substr(p,n);
    }

    int minimumGroups(vector<string>&words){
        // Canonical pair store karenge
        vector<pair<string,string>>canonicals;

        canonicals.reserve(words.size());

        string a;
        string b;

        for(const string&w:words){
            a.clear();
            b.clear();

            // Even aur Odd alag karlo
            for(int i=0;i<w.size();i++){

                if(i&1){
                    b+=w[i];
                }
                else{
                    a+=w[i];
                }
            }
            // Dono ki smallest cyclic rotation nikalo
            string x=fun(a);
            string y=fun(b);

            // Canonical pair store kardo
            canonicals.emplace_back(x,y);
        }
        // Same canonical pairs ko paas paas le aao
        sort(canonicals.begin(),canonicals.end());

        // Duplicate hata do
        auto it=unique(canonicals.begin(),canonicals.end());

        // Unique groups ki count
        return distance(canonicals.begin(),it);
    }
};