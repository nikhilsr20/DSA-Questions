class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        count=1
        ans=0
        prev=0

        

        for i in range(1,len(s)):
            if s[i]==s[i-1]:
                count=count+1
            else:
                if prev==0:
                    prev=count
                else:
                    ans=ans+min(prev,count)
                    prev=count
                count=1
        ans=ans+min(prev,count)

        return ans                

        
