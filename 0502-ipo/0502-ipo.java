class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {

        int n=profits.length;     // Kisi ka bhi Size lelo dono Same hai
        int[][] proj=new int[n][2];     // Pair lelo

        for(int i=0;i<n;i++){
            proj[i][0]=capital[i];
            proj[i][1]=profits[i];       // Iss Structure mein daal ke karlo Pair
        }

        Arrays.sort(proj,(a,b)->a[0]-b[0]);        // Ascending mein Sort hojaega

        PriorityQueue<Integer> pq=new PriorityQueue<>(Collections.reverseOrder());     // Max Heap

        int idx=0;                             // Pair wley Array ke liye Index Ptr

        while(k-- > 0){

            while(idx<n){

                if(proj[idx][0]>w){
                    // Nahi aaskata hai
                    break;
                }

                // Agar aaskata hai tab
                pq.offer(proj[idx][1]);        // Profits k hisab se Store karlo

                idx++;                         // Inc kartey chlo
            }

            // Edge Case
            if(pq.isEmpty()){
                return w;
            }

            w=w+pq.poll();          // Max Profit wley ko lekey Add kardo w mein
        }
        return w;             // Final Max Capital
    }
}