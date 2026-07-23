public class Solution
{
    public void Fun(string digits,int n,int idx,List<char> diary,List<string> res,Dictionary<char,string> f)
    {
        // Last wla stage lelo
        if(idx==n)
        {
            res.Add(new string(diary.ToArray()));      // res hi mein push back kardo diary wla
            return;
        }

        // Strings ko button ke nichey hai sab ek sath nilega
        string choice=f[digits[idx]];

        for(int j=0;j<choice.Length;j++)
        {
            // Push kardo har j k index ko
            diary.Add(choice[j]);

            // Explore karlo next wley mei jakey
            Fun(digits,n,idx+1,diary,res,f);

            // Reverse kardo
            diary.RemoveAt(diary.Count-1);
        }
        return;
    }

    public IList<string> LetterCombinations(string digits)
    {
        Dictionary<char,string> f=new Dictionary<char,string>();

        // HashMap dec kardo taki sab ek sath ajae(1-9 tak)
        f['2']="abc";
        f['3']="def";
        f['4']="ghi";
        f['5']="jkl";
        f['6']="mno";
        f['7']="pqrs";
        f['8']="tuv";
        f['9']="wxyz";

        int n=digits.Length;
        List<char> diary=new List<char>();     // shuru mein empty hi hoga
        List<string> res=new List<string>();   // Result k liye

        if(n==0)
        {
            return res;
        }

        // Recursive Call kardo intio main
        Fun(digits,n,0,diary,res,f);

        return res;
    }
}