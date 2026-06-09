class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        a={}
        ans=[]
        b={}
        count=0
        for x,y in queries:
            if a.get(x,-1)==-1:
                a[x]=y
                b[y]=b.get(y,0)+1
                if b[y]==1:
                    count+=1
            else:
                p=a[x]
                b[p]=b.get(p,0)-1
                if b[p]==0:
                    count-=1
                a[x]=y
                b[y]=b.get(y,0)+1
                if b[y]==1:
                    count+=1

            ans.append(count)

        return ans        






        return ans    
