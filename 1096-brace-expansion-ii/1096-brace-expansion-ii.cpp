class Solution {
public:
    set<string> fun(string s,int& i){
        set<string>res;
        set<string>curr;
        curr.insert("");

        while(i<s.size() && s[i]!='}'){
            if(s[i]=='{'){
                i++;
                set<string>temp=fun(s,i);
                i++;
                set<string>next;

                // Current strings ke saath temp ko combine karo
                for(auto a:curr){
                    for(auto b:temp){
                        next.insert(a+b);
                    }
                }
                curr=next;
            }
            else if(s[i]==','){
                // Current part ko result mein daal do
                for(auto x:curr){
                    res.insert(x);
                }
                curr.clear();
                curr.insert("");

                i++;
            }
            else{
                // Normal character
                set<string>next;

                for(auto x:curr){
                    next.insert(x+s[i]);
                }
                curr=next;
                i++;
            }
        }
        // Last part ko result mein daal do
        for(auto x:curr){
            res.insert(x);
        }
        return res;
    }

    vector<string> braceExpansionII(string expression){
        int i=0;
        set<string>res=fun(expression,i);
        vector<string>ans;

        for(auto x:res){
            ans.push_back(x);
        }
        return ans;
    }
};