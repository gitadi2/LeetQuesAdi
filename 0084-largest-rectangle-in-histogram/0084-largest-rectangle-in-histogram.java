class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stk=new Stack<>();
        int n=heights.length;
        int res=0;

        for(int i=0;i<=n;i++){
            int curr=(i==n)?0:heights[i];

            while(!stk.empty() && heights[stk.peek()]>curr){
                int h=heights[stk.peek()];
                stk.pop();

                int left=stk.empty()?-1:stk.peek();
                int width=i-left-1;

                res=Math.max(res,h*width);
            }

            stk.push(i);
        }

        return res;
    }
}