class Solution {

    class Node{
        int freq;
        char ch;

        Node(int freq,char ch){
            this.freq=freq;
            this.ch=ch;
        }
    }

    class cmp implements Comparator<Node>{

        public int compare(Node a,Node b){

            if(a.freq!=b.freq){
                return b.freq-a.freq;          // Max Heap on the First one
            }

            return b.ch-a.ch;                 // Max Heap on the Second one
        }
    }

    public String reorganizeString(String s) {

        int n=s.length();

        // HashMap Declaration
        HashMap<Character,Integer> mp=new HashMap<>();

        // Loop for the HashMap
        for(int i=0;i<n;i++){
            mp.put(s.charAt(i),mp.getOrDefault(s.charAt(i),0)+1);
        }

        // Priority Queue Declaration
        PriorityQueue<Node> pq=new PriorityQueue<>(new cmp());

        // Inserting the Elements along with their Frequency into the Priority Queue
        for(Map.Entry<Character,Integer> it:mp.entrySet()){
            pq.offer(new Node(it.getValue(),it.getKey()));
        }

        StringBuilder res=new StringBuilder();      // Initially String will be Empty and this will be the Resultant String
        int slot=0;                                 // Slot too Empty

        while(!pq.isEmpty()){

            // Jab tak pq Empty nahi hai
            Node p1=pq.poll();                      // Heap ke Top Element ko Dekho

            if(slot==0 || res.charAt(slot-1)!=p1.ch){

                // Matlab agar Result Empty hai OR Element Different hai to daal sakte hain
                res.append(p1.ch);

                slot++;                            // Slot ko bada do

                p1.freq--;                         // Frequency Kam Kardo

                if(p1.freq>0){
                    pq.offer(p1);                  // Agar Frequency bachi hai toh Heap mein Push Kardo
                }

                continue;
            }

            // Same Character aa gaya Adjacent Position par

            if(pq.isEmpty()){
                return "";
            }

            Node p2=pq.poll();                     // Heap ke Second Maximum Frequency wale Character ko lo

            res.append(p2.ch);

            slot++;

            p2.freq--;

            pq.offer(p1);                          // Pehla Character Wapas Heap mein Push Kardo

            if(p2.freq>0){
                pq.offer(p2);
            }
        }

        return res.toString();
    }
}