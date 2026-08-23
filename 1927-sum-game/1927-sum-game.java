class Solution {
    public boolean sumGame(String num) {

        int n=num.length();

        int left=0;
        int right=0;

        int qleft=0;
        int qright=0;

        // Left aur Right ka sum + ? count nikal lo
        for(int i=0;i<n;i++){
            if(num.charAt(i)=='?'){
                if(i<n/2){
                    qleft++;
                }
                else{
                    qright++;
                }
            }
            else{
                if(i<n/2){
                    left+=num.charAt(i)-'0';
                }
                else{
                    right+=num.charAt(i)-'0';
                }
            }
        }

        int diff=left-right;

        // Agar ? ki count odd hai
        if((qleft+qright)%2==1){
            return true;
        }

        // Question marks equal hain
        if(qleft==qright){
            return diff!=0;
        }

        int qdiff=Math.abs(qleft-qright);

        // Extra question marks left side par hain
        if(qleft>qright){
            return diff+9*(qdiff/2)!=0;
        }

        // Extra question marks right side par hain
        return diff-9*(qdiff/2)!=0;
    }
}