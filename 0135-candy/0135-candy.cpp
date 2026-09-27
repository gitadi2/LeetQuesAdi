// Most Optimal Appraoach (Slope Method)

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int sum=1;          // Intially sum var lo and dec it as 1 cuz atleast 1 toh dena hi hgai sabko 
        int i=1;

        while(i<n){
            // Flat Surface ka case 
            if(ratings[i]==ratings[i-1]){
                sum++;
                i++;
                continue;
            }

            // Increasing Slope k liye 
            int peak=1;        // Peak Elem k liye 
            while(i<n && ratings[i]>ratings[i-1]){
                sum+=peak+1;
                i++;
                peak++;
            }

            // Decreasing Slope ka case 
            int down=1;   // Dec elem k liye 
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                i++;
                down++;
            }
            if(down>peak){
                sum+=down-peak;              // Sum + down and peak ka diff = tot sum dega 
            }
        }
        return sum;
    }
};