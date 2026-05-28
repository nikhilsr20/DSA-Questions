class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        ans=s
        for i in range(0,10):
            if b%2==0:
                i=0
      
            for j in range(0,10):
              
                c=""
                for k in range(0,len(s)):
                    if k%2==0:
                        c+=(str((int(s[k])+(a*i))%10))
                    else:
                        c+=(str((int(s[k])+(a*j))%10))
               
                
                ans=min(c,ans)
                for k in range(0,len(s)):
                    c = c[-b:] + c[:-b]
                    
                    ans=min(c,ans)
                 

                       
                   


        return ans      


                

                