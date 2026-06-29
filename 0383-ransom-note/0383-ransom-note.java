class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int n=ransomNote.length();      // Len of the Ransom Note String
        int m=magazine.length();        // Len of the Magazine String

        HashMap<Character, Integer> need=new HashMap<>();   // Declaration of the Need HashMap (Ransom Note)
        HashMap<Character, Integer> have=new HashMap<>();   // Declaration of the Have HashMap (Magazine)

        for(int i=0;i<n;i++){
            need.put(ransomNote.charAt(i), need.getOrDefault(ransomNote.charAt(i), 0) + 1);
        }

        for(int i=0;i<m;i++){
            have.put(magazine.charAt(i), have.getOrDefault(magazine.charAt(i), 0) + 1);
        }

        return fun(have,need);
    }

    public boolean fun(HashMap<Character, Integer> have, HashMap<Character, Integer> need){
        for(Map.Entry<Character, Integer> i:need.entrySet()){
            char c=i.getKey();         // Key one
            int fneed=i.getValue();    // Value One
            int fhave=have.getOrDefault(c, 0);   // The freq of that letter in have

            if(fhave<fneed){
                return false;
            }
        }
        return true;
    }
}