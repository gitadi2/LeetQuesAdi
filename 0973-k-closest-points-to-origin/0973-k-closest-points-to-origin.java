class Solution {
    class Pair{
        int first;
        int second;

        Pair(int first,int second){
            this.first=first;
            this.second=second;
        }
    }

    public int[][] kClosest(int[][] points, int k) {
        int n=points.length;

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
            int x=points[i][0];
            int y=points[i][1];

            int dist=x*x+y*y;

            Pair curr=new Pair(dist,i);           // Iss trh se raka jaega

            if(pq.size()<k){
                // Still in the Process ; toh randomly push k elements and move fwd
                pq.add(curr);
                continue;
            }

            if(curr.first>=pq.peek().first){
                // skip and move fwd
                continue;
            }

            pq.poll();
            pq.add(curr);
        }

        int[][] res=new int[k][2];               // Taking a 2D array of the Resultant
        int idx=0;

        while(!pq.isEmpty()){
            res[idx++]=points[pq.peek().second]; // Res 2D array mein second wley ko push kardo
            pq.poll();                            // ab pop kardo
        }

        return res;                               // Resultant 2D array return kardo
    }
}