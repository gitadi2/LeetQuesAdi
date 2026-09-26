class Solution {
public:
    string evaluate(string s,vector<vector<string>>&knowledge){
        unordered_map<string,string>mp;

        // Saare key-value pairs ko map mein store karo
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        string res="";

        // String ko traverse karo
        for(int i=0;i<s.size();i++){
            // Agar opening bracket '(' mila
            if(s[i]=='('){
                i++;
                string key="";
                // Closing bracket ')' tak key banao
                while(s[i]!=')'){
                    key+=s[i];
                    i++;
                }
                // Agar key map mein present hai
                if(mp.find(key)!=mp.end()){
                    res+=mp[key];
                }
                // Agar key map mein present nahi hai
                else{
                    res+="?";
                }
            }
            // Normal character ko result mein add karo
            else{
                res+=s[i];
            }
        }
        return res;
    }
};