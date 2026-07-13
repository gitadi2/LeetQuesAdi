from collections import Counter
import heapq

class Solution:

    def reorganizeString(self, s: str) -> str:

        n=len(s)

        # HashMap Declaration
        mp=Counter()

        # Loop for the HashMap
        for ch in s:
            mp[ch]+=1

        # Priority Queue Declaration
        pq=[]

        # Inserting the Elements along with their Frequency into the Priority Queue
        for ch,freq in mp.items():
            heapq.heappush(pq,(-freq,-ord(ch),ch))

        res=""                          # Initially String will be Empty and this will be the Resultant String
        slot=0                          # Slot too Empty

        while pq:

            # Jab tak pq Empty nahi hai
            freq1,neg1,ch1=heapq.heappop(pq)       # Heap ke Top Element ko Dekho

            if slot==0 or res[slot-1]!=ch1:

                # Matlab agar Result Empty hai OR Element Different hai to daal sakte hain
                res+=ch1                           # Different hai toh daal do

                slot+=1                            # Slot ko bada do

                freq1+=1                           # Frequency Kam Kardo

                if freq1<0:
                    heapq.heappush(pq,(freq1,neg1,ch1))     # Agar Frequency bachi hai toh Heap mein Push Kardo

                continue

            # Same Character aa gaya Adjacent Position par

            if not pq:
                return ""

            freq2,neg2,ch2=heapq.heappop(pq)       # Heap ke Second Maximum Frequency wale Character ko lo

            res+=ch2

            slot+=1

            freq2+=1

            heapq.heappush(pq,(freq1,neg1,ch1))    # Pehla Character Wapas Heap mein Push Kardo

            if freq2<0:
                heapq.heappush(pq,(freq2,neg2,ch2))

        return res