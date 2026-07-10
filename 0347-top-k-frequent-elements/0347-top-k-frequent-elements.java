class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int n=nums.length;

        PriorityQueue<int[]> pq=new PriorityQueue<>((a,b)->{
            if(a[0]!=b[0]){
                return a[0]-b[0];
            }
            return a[1]-b[1];
        });

        HashMap<Integer,Integer> mp=new HashMap<>();

        for(int i=0;i<n;i++){
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        }

        for(Map.Entry<Integer,Integer> i:mp.entrySet()){
            int element=i.getKey();
            int freq=i.getValue();

            int[] curr={freq,element};

            if(pq.size()<k){
                pq.add(curr);
                continue;
            }

            if(curr[0]<pq.peek()[0]){
                continue;
            }

            pq.poll();
            pq.add(curr);
        }

        int[] res=new int[k];
        int idx=0;

        while(!pq.isEmpty()){
            res[idx++]=pq.poll()[1];
        }

        return res;
    }
}