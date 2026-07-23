class Solution {
public:
void fun(string& digits, int n, int idx,string& diary, vector<string>&res,unordered_map<char,string>&f){
    // Last wla stage lelo 
    if(idx==n){
        res.push_back(diary);            // res hi mein push back kardo diary wla 
        return;
    }

    // Strings ko button ke nichey hai sab ek sath nilega 
    string choice=f[digits[idx]];
    for(int j=0;j<choice.size();j++){
        // Push kardo har j k index ko 
        diary.push_back(choice[j]);     // y j=0 se jo char ho ; uska nikal dega same krta rahe
        fun(digits,n,idx+1,diary,res,f);   // Explore karlo next wley mei  jakey 
        diary.pop_back();                  // Reverse kardo 
    }
    return;
}

    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>f;        // HashMap dec kardo taki sab ek sath ajae(1-9 tak)
        f['2']="abc";
        f['3']="def";
        f['4']="ghi";
        f['5']="jkl";
        f['6']="mno";
        f['7']="pqrs";
        f['8']="tuv";
        f['9']="wxyz";

        int n=digits.size();
        string diary="";                // shuru mein empty hi hoga 
        vector<string>res;              // Result k liye 

        // Recursive Call kardo intio main 
        fun(digits,n,0,diary,res,f);

        return res; 
    }
};