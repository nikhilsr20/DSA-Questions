class Solution:
    def processStr(self, s: str) -> str:
        ans=[]
        for i in s:
            if i=='#':
                p=ans.copy()
                ans.extend(p)
            elif i=='*' :
                if len(ans)>0:
                    ans.pop()
            elif i=='%':
                ans.reverse()
            else:
                ans.append(i)

        return ''.join(ans)            



            
