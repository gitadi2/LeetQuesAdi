class Solution {
public:
    bool sumGame(string num) {

        int n=num.size();

        int left=0;
        int right=0;

        int qleft=0;
        int qright=0;

        // Left aur Right ka sum + ? count nikal lo
        for(int i=0;i<n;i++){
            if(num[i]=='?'){
                if(i<n/2){
                    qleft++;
                }
                else{
                    qright++;
                }
            }

            else{
                if(i<n/2){
                    left+=num[i]-'0';
                }
                else{
                    right+=num[i]-'0';
                }
            }
        }

        int diff=left-right;

        // Agar ? ki count odd hai
        if((qleft+qright)%2==1){
            return true;
        }

        // Question marks equal hain dono players apna best move karenge
        if(qleft==qright){
            return diff!=0;
        }

        // Extra question marks jis side hain
        int qdiff=abs(qleft-qright);

        // Difference ko compensate karne ke liye required sum
        if(qleft>qright){
            return diff+9*(qdiff/2)!=0;
        }
        else{
            return diff-9*(qdiff/2)!=0;
        }
    }
};