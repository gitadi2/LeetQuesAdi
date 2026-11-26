// Greedy (Simulation)

class Solution {
    public boolean canAliceWin(int n) {
        int x=10;
        int cnt=0;

        while(x>0 && n>=x){
            n-=x;
            x--;
            cnt++;
        }
        return cnt%2==1;
    }
}