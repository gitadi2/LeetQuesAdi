class Pair:
    def __init__(self,freq,word):
        self.first=freq
        self.second=word

    def __lt__(self,other):
        if(self.first!=other.first):
            return self.first<other.first
        return self.second>other.second


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        n=len(words)

        # Priority Queue Declaration
        pq=[]

        # Hashmap Declaration
        mp={}

        # Loop for the Hashmap
        for i in range(n):
            mp[words[i]]=mp.get(words[i],0)+1

        for i in mp.items():
            words=i[0]
            freq=i[1]

            curr=Pair(freq,words)

            if(len(pq)<k):
                heapq.heappush(pq,curr)
                continue

            if(curr.first<pq[0].first):
                continue

            if(curr.first==pq[0].first and curr.second>pq[0].second):
                continue

            heapq.heappop(pq)
            heapq.heappush(pq,curr)

        res=[]

        while(pq):
            res.append(pq[0].second)
            heapq.heappop(pq)

        res.reverse()

        return res