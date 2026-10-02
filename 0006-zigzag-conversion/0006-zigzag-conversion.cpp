class Solution {
public:
    string convert(string s,int numRows){
        int n=s.size();

        if(numRows==1 || numRows>=n){
            return s;
        }
        vector<string>v(numRows);

        int row=0;
        int dir=1;

        // String ko traverse karo
        for(int i=0;i<n;i++){
            // Current character ko current row mein daalo
            v[row]+=s[i];
            // Agar first row par ho toh neeche jao
            if(row==0){
                dir=1;
            }
            // Agar last row par ho toh upar jao
            else if(row==numRows-1){
                dir=-1;
            }
            row+=dir;
        }

        string res="";
        
        // Saari rows ko combine karo
        for(int i=0;i<numRows;i++){
            res+=v[i];
        }
        return res;
    }
};