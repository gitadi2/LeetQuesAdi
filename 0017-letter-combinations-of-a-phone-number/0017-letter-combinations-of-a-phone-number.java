class Solution {
    public void fun(String digits,int n,int idx,StringBuilder diary,List<String> res,HashMap<Character,String> f){

        // Last wla stage lelo
        if(idx==n){
            res.add(diary.toString());      // res hi mein push back kardo diary wla
            return;
        }

        // Strings ko button ke nichey hai sab ek sath nilega
        String choice=f.get(digits.charAt(idx));

        for(int j=0;j<choice.length();j++){

            // Push kardo har j k index ko
            diary.append(choice.charAt(j));

            // Explore karlo next wley mei jakey
            fun(digits,n,idx+1,diary,res,f);

            // Reverse kardo
            diary.deleteCharAt(diary.length()-1);
        }
        return;
    }

    public List<String> letterCombinations(String digits) {
        HashMap<Character,String> f=new HashMap<>();

        // HashMap dec kardo taki sab ek sath ajae(1-9 tak)
        f.put('2',"abc");
        f.put('3',"def");
        f.put('4',"ghi");
        f.put('5',"jkl");
        f.put('6',"mno");
        f.put('7',"pqrs");
        f.put('8',"tuv");
        f.put('9',"wxyz");

        int n=digits.length();
        StringBuilder diary=new StringBuilder();     // shuru mein empty hi hoga
        List<String> res=new ArrayList<>();          // Result k liye

        if(n==0){
            return res;
        }
        // Recursive Call kardo intio main
        fun(digits,n,0,diary,res,f);

        return res;
    }
}