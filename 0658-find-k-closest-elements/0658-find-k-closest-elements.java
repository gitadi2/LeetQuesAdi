class Solution {
    class Pair{
        int first;
        int second;

        Pair(int first,int second){
            this.first=first;
            this.second=second;
        }
    }

    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int n=arr.length;

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
            int element=arr[i];

            int dist=Math.abs(element-x);

            Pair curr=new Pair(dist,element);          // Iss trh se raka jaega

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
                // Same Distance par bada element hai toh skip
                continue;
            }

            pq.poll();
            pq.add(curr);
        }

        List<Integer> res=new ArrayList<>();           // Taking an Array of the Resultant

        while(!pq.isEmpty()){
            res.add(pq.peek().second);                 // Res Array mein second wley ko push kardo
            pq.poll();                                 // ab pop kardo
        }

        Collections.sort(res);                         // Final Ans Sorted Order mein chahiye

        return res;                                    // Resultant Array return kardo
    }
}