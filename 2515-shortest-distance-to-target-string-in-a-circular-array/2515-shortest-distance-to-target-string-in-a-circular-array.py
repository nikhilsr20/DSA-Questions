class Solution:
    def closestTarget(self, words: List[str], target: str, s: int) -> int:
        ans=float("inf")
        c=0
        for i in range(s,s+len(words)):
            i=i%len(words)
            # print(i)
            if words[i]==target:
   
                ans=min(c,ans)
         
            c=c+1

        c=0
        for i in range(s,s-len(words),-1):
            i=(i+len(words))%len(words)
           
            if words[i]==target:
                ans=min(c,ans)

            c=c+1    

        if ans==float("inf"):
            return -1
        return ans        



        