class Solution {
    public int leastInterval(char[] tasks, int n) {

        int m=tasks.length;

        HashMap<Character,Integer> freq=new HashMap<>();
        HashMap<Character,Integer> free=new HashMap<>();

        for(int i=0;i<m;i++){

            freq.put(tasks[i],freq.getOrDefault(tasks[i],0)+1);      // Har Baar freq mein jo tasks hai uska isi loop se inc hoga

            if(!free.containsKey(tasks[i])){
                free.put(tasks[i],1);      // Starting mein 1 par beth sakta haii
            }
        }

        // Dec of the Priority Queue
        PriorityQueue<int[]> pq=new PriorityQueue<>((a,b)->b[0]-a[0]);

        for(Map.Entry<Character,Integer> i:freq.entrySet()){
            pq.add(new int[]{i.getValue(),i.getKey()});
        }

        int seat=1;

        while(!pq.isEmpty()){

            ArrayList<int[]> pulled=new ArrayList<>();      // Koney wla elemnts pair mei jo aaengey unkey liye array

            while(!pq.isEmpty()){

                int[] p=pq.poll();      // top wla bachha

                int fr=p[0];
                char child=(char)p[1];

                if(free.get(child)<=seat){

                    if(fr>1){
                        pq.add(new int[]{fr-1,child});
                    }

                    free.put(child,seat+n+1);
                    break;
                }
                else{
                    pulled.add(p);
                }
            }
            for(int i=0;i<pulled.size();i++){
                pq.add(pulled.get(i));
            }
            seat++;
        }
        return seat-1;
    }
}