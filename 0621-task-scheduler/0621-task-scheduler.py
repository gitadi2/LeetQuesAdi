import heapq

class Solution:
    def leastInterval(self,tasks,n):

        m=len(tasks)

        freq={}
        free={}

        for i in range(m):

            freq[tasks[i]]=freq.get(tasks[i],0)+1      # Har Baar freq mein jo tasks hai uska isi loop se inc hoga

            if tasks[i] not in free:
                free[tasks[i]]=1      # Starting mein 1 par beth sakta haii

        # Dec of the Priority Queue
        pq=[]

        for k,v in freq.items():
            heapq.heappush(pq,(-v,k))

        seat=1

        while pq:

            pulled=[]      # Koney wla elemnts pair mei jo aaengey unkey liye array

            while pq:

                fr,child=heapq.heappop(pq)      # top wla bachha

                fr=-fr

                if free[child]<=seat:

                    if fr>1:
                        heapq.heappush(pq,(-(fr-1),child))

                    free[child]=seat+n+1
                    break

                else:
                    pulled.append((-fr,child))

            for x in pulled:
                heapq.heappush(pq,x)

            seat+=1

        return seat-1