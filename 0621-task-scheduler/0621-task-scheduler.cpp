class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m=tasks.size();

        unordered_map<char,int> freq;
        unordered_map<char,int> free;

        for(int i=0;i<m;i++){
            freq[tasks[i]]++;         // Har baar freq mein jo tasks hai uska isi loop se inc hoga

            if(free.find(tasks[i])==free.end()){
                free[tasks[i]]=1;     // Starting mein 1 par beth sakta haii
            }
        }

        priority_queue<pair<int,char>> pq;      // Dec of the Priority Queue

        for(auto i:freq){
            pq.push({i.second,i.first});
        }

        int seat=1;

        while(!pq.empty()){

            vector<pair<int,char>> pulled;        // Koney wla elemnts pair mei jo aaengey unkey liye array

            while(!pq.empty()){

                pair<int,char> p=pq.top();        // top wla bachha
                pq.pop();                         // 1 bachhha nikla

                int fr=p.first;
                char child=p.second;

                if(free[child]<=seat){

                    if(fr>1){
                        pq.push({fr-1,child});
                    }

                    free[child]=seat+n+1;
                    break;
                }
                else{
                    pulled.push_back(p);
                }
            }

            for(int i=0;i<pulled.size();i++){
                pq.push(pulled[i]);
            }
            seat++;
        }
        return seat-1;
    }
};