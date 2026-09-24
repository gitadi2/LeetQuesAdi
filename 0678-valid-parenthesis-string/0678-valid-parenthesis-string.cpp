// Range Based Approach 

class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int min=0;            // Min of the Range 
        int max=0;           // Max of the Range 

        for(int i=0;i<n;i++){
            //Agar '(' mila 
            if(s[i]=='('){
                min++;
                max++;
            }
            //Agar ')' mila 
            else if(s[i]==')'){
                min--;
                max--;
            }
            // Agar '*' mila 
            else{
                min--;
                max++;
            }
            if(min<0){
                min=0;          // agr min -ve hua toh update it to zero 
            }
            if(max<0){
                return false;
            }
        }
        return min==0;               // Yni ki possible valid parenthesis hai toh whi
    }
};