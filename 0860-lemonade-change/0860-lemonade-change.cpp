class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;                             // Intit of $5
        int ten=0;                              //Init of $10
        int twenty=0;                            // Init of $ 20

        int n=bills.size();

        for(int i=0;i<n;i++){
            // Purey array ko Traverse karkey dekho 
            if(bills[i]==5){
                // Agar 5 Mil jata hai 
                five+=1;                       // Add karo 5 into the change 
            }
            else if(bills[i]==10){
                // Agar 10 Mila 
                if(five){
                    // Agar Change mei Five hai 
                    five-=1;
                    ten+=1;
                }
                else{
                    return false;                // $5 change mein nhi bai tih $10 mat lo as change na
                }
            }
            else{
                // Agar 20 Mila 
                if(five && ten){
                    // Agar 5 and 10 hai tabhi lo 
                    five-=1;
                    ten-=1;
                }
                else if(five>=3){
                    // Agar five 3 se yada bar arry mei hai 
                    five-=3;               // $5 k 3 coins change kardo 
                }
                else{
                    // Agar kch nhi hai toh $20 mat lo 
                    return false;
                }
            }
        }
        return true;                       // Agar Pura hi shi se Chl jata hai toh return true 
    }
};