class Solution {
    public int lastStoneWeight(int[] stones) {

        int n=stones.length;

        PriorityQueue<Integer> pq=new PriorityQueue<>(Collections.reverseOrder());     // Max Heap Dec

        // Inserting all the Stones into the Heap
        for(int i=0;i<n;i++){
            pq.offer(stones[i]);
        }

        // Jab tak Heap mein 1 se Zyada Stones hain
        while(pq.size()>1){

            int first=pq.poll();          // Largest Stone

            int second=pq.poll();         // Second Largest Stone

            if(first==second){
                // Stones are Destroyed
                continue;
            }

            // New Wt = y-x
            pq.offer(first-second);
        }

        // Agar Heap Empty hai
        if(pq.isEmpty()){
            return 0;
        }

        return pq.peek();          // The Last Remaining Stone
    }
}