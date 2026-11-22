// Greedy (Single Traversal)

class Solution {
public:
    bool checkString(string s) {
        int n=s.size();

        bool flag=false;

        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                flag=true;
            }
            else if(s[i]=='a' && flag==true){
                return false;
            }
        }
        return true;
    }
};