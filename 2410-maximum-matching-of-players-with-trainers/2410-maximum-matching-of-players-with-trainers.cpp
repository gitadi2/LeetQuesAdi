class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n=players.size();
        int m=trainers.size();

        sort(players.begin(),players.end());             // Players k arry ko sort karlo 
        sort(trainers.begin(),trainers.end());           // Trainers k arry ko bhi sort karlo 

        int i=0;                                        // Players k ptr ka start 
        int j=0;                                         // Trainers arrys k ptr ka start

        while(i<n && j<m){
            if(players[i]<=trainers[j]){
                // Agar player ki ability kaam ya equal hui trainer k se 
                i++;
                j++;
            }
            else{
                // Agar esa nhi hai 
                j++;                                         // Tariner ko agey badhaoi mat lo 
            }
        }
        return i;
    }
};