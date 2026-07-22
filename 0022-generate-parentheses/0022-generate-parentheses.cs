public class Solution
{
    public void Fun(int open,int close,int n,List<char> tmp,List<string> res)
    {
        if(open==n && close==n)
        {
            // Jab Limit wla hit hojae
            res.Add(new string(tmp.ToArray()));
            return;
        }

        // Open wla Parenthesis k liye
        if(open<n)
        {
            tmp.Add('(');
            Fun(open+1,close,n,tmp,res);
            tmp.RemoveAt(tmp.Count-1);
        }

        // Close Wala Parenthesis lelo
        if(close<open)
        {
            tmp.Add(')');
            Fun(open,close+1,n,tmp,res);
            tmp.RemoveAt(tmp.Count-1);
        }
    }

    public IList<string> GenerateParenthesis(int n)
    {
        List<string> res=new List<string>();
        List<char> tmp=new List<char>();

        // Recursive Function Call kardo
        Fun(0,0,n,tmp,res);

        return res;
    }
}