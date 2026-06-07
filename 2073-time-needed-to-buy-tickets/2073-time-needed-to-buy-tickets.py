from collections import deque

class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        q=deque()

        for i in range(0,len(tickets)):
            if i==k:
                q.append(-tickets[i])
            else:
                q.append(tickets[i])
        ans=0
        while True:
            if q[0]>0:
                ans+=1
                x=q[0]-1
                q.popleft()
                if x!=0:
                    q.append(x)

            else:
                ans+=1    
                x=q[0]+1
                q.popleft()
                q.append(x)
                if x==0:
                   break

        return ans       


