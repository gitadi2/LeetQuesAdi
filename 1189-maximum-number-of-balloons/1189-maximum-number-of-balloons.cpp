class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.size();

        unordered_map<char,int> have;           // The Hashmap of have declaration
        for(int i=0;i<n;i++){
            have[text[i]]++;
        }

        unordered_map<char,int>need;            // The Hashmap of the need Declaration
        need['b']=1;
        need['a']=1;
        need['l']=2;
        need['o']=2;
        need['n']=1;

        int res=INT_MAX;                        // The Minimum req will decide the ans

        for(auto i:need){
            char c=i.first;          //Key 
            int fneed=i.second;      //Value 
            int fhave=have[c];       // Have is being taken on from the have hashmap with the letters
            int times=fhave/fneed;   // Gives the times 

            res=min(res,times);      //The Min of the both will be the ans
        }
        return res;                  // The Min no. of the times {The Final Answer}
    }
};