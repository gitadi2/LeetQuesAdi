class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int n=heights.size();
        int res=0;

        for(int i=0;i<=n;i++){
            int curr=(i==n)?0:heights[i];

            while(!stk.empty() && heights[stk.top()]>curr){
                int h=heights[stk.top()];
                stk.pop();

                int left=stk.empty()?-1:stk.top();           //Ternary Operator
                int width=i-left-1;

                res=max(res,h*width);
            }

            stk.push(i);
        }

        return res;
    }
};