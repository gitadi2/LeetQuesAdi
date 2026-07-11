class Solution {
    class Pair{
        int first;
        int second;

        Pair(int first,int second){
            this.first=first;
            this.second=second;
        }
    }

    public int[] kWeakestRows(int[][] mat, int k) {
        int n=mat.length;
        int m=mat[0].length;

        // Priority Queue Declaration
        PriorityQueue<Pair> pq=new PriorityQueue<>((a,b)->{
            if(a.first!=b.first){
                // Max wla first lena hai
                return b.first-a.first;
            }
            // Max wala hi second lena hogaaa
            return b.second-a.second;
        });

        for(int i=0;i<n;i++){
            int soldier=0;

            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    soldier++;
                }
            }

            Pair curr=new Pair(soldier,i);          // Iss trh se raka jaega

            if(pq.size()<k){
                // Still in the Process ; toh randomly push k elements and move fwd
                pq.add(curr);
                continue;
            }

            if(curr.first>pq.peek().first){
                // skip and move fwd
                continue;
            }

            if(curr.first==pq.peek().first && curr.second>=pq.peek().second){
                // Same Soldiers par bada Row Index hai toh skip
                continue;
            }

            pq.poll();
            pq.add(curr);
        }

        int[] res=new int[k];                       // Taking an Array of the Resultant
        int idx=0;

        while(!pq.isEmpty()){
            res[idx++]=pq.peek().second;             // Res Array mein second wley ko push kardo
            pq.poll();                               // ab pop kardo
        }

        for(int i=0;i<k/2;i++){
            int temp=res[i];
            res[i]=res[k-i-1];
            res[k-i-1]=temp;
        }

        return res;                                  // Resultant Array return kardo
    }
}