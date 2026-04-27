class Solution:
    def calculateScore(self, ins: List[str], values: List[int]) -> int:
        score=0
        j=0
        l=[False for _ in range(len(ins))]
        while j>=0 and j<len(values):
            if l[j]==True:
                break


            if ins[j]=='jump':
                l[j]=True
                if j<len(values): 
                   j=j+values[j]
            else:
                l[j]=True
                if j<len(values): 
                   score+=values[j]
                j=j+1
                


             
        return score       