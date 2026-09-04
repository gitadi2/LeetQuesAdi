class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();

        sort(g.begin(),g.end());                // Greed Factor k arry ko sort kardo 
        sort(s.begin(),s.end());                // No. of Cookie k array ko bhi sort kardo 

        int i=0;                             // Left ptr ko shuru mei g wley arry k start par rakho
        int j=0;                             // Right ptr ko start mei s wley arry k start par rakho

        while(i<n && j<m){
            // Jab  tak left ptr range of arry mei hai and right wla bhi 
            if(s[j]>=g[i]){
                // agr no. of cookies greed factor se bda hai, toh dono ko badha do 
                i++;
                j++;
            }
            else{
                // Agar esa nhi hai : Yani ki s[j]<g[i]
                j++;                             // Size wley ptr ko badha do 
            }
        }
        return i;                               // Greed array mei jitna i chalega whi ans return kardo 
    }
};