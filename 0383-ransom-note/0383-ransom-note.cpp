class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=ransomNote.size();     // Len of the Ransom Note String
        int m=magazine.size();       // Len of the Magazine String

        unordered_map<char,int> need;   // Declaration of the Need Hashmap (Ransom Note)
        unordered_map<char,int> have;   // Declaration of the Have Hashmap (Magazine)

        for(int i=0;i<n;i++){
            need[ransomNote[i]]++;
        }

        for(int i=0;i<m;i++){
            have[magazine[i]]++;
        }

        return fun(have,need);
    }

    bool fun(unordered_map<char,int>have,unordered_map<char,int>need){
        for(auto i:need){
            char c=i.first;      // Key one 
            int fneed=i.second;  // Value One 
            int fhave=have[c];   //The freq of that letter in have

            if(fhave<fneed){
                return false;
            }
        }
        return true;
    }
};