class Solution:
    def arrangeWords(self, text: str) -> str:
        s=text.split()
        s=[i.lower() for i in s]
        ans=[]

        for _ in range(len(s)): 
            a2=float('inf')
            b=0
            for j in range(0,len(s)):
                if a2>len(s[j]) :
                   a2=min(a2,len(s[j]))
                   b=j
            ans.append(s[b])
            s.pop(b)

        ans=' '.join(ans)
        ans=ans[0].upper()+ans[1:]
        return ans    
                
                
