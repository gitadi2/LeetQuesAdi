class Solution {
    class Pair{
        int freq;
        String word;

        Pair(int freq,String word){
            this.freq=freq;
            this.word=word;
        }
    }

    public List<String> topKFrequent(String[] words, int k) {
        int n=words.length;

        PriorityQueue<Pair> pq=new PriorityQueue<>((a,b)->{
            if(a.freq!=b.freq){
                return a.freq-b.freq;
            }
            return b.word.compareTo(a.word);
        });

        HashMap<String,Integer> mp=new HashMap<>();

        for(int i=0;i<n;i++){
            mp.put(words[i],mp.getOrDefault(words[i],0)+1);
        }

        for(Map.Entry<String,Integer> i:mp.entrySet()){
            String word=i.getKey();
            int freq=i.getValue();

            Pair curr=new Pair(freq,word);

            if(pq.size()<k){
                pq.add(curr);
                continue;
            }

            if(curr.freq<pq.peek().freq){
                continue;
            }

            if(curr.freq==pq.peek().freq && curr.word.compareTo(pq.peek().word)>0){
                continue;
            }

            pq.poll();
            pq.add(curr);
        }

        List<String> res=new ArrayList<>();

        while(!pq.isEmpty()){
            res.add(pq.poll().word);
        }

        Collections.reverse(res);

        return res;
    }
}