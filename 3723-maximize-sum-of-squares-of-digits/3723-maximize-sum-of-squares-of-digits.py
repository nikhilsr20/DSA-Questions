class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        ans=""
        while sum!=0 and num!=0:
            ans=ans+str(min(sum,9))
            sum-=min(sum,9)
            num=num-1
        
        if sum==0:
            while num!=0:
                ans=ans+'0'
                num=num-1
            return str(ans)
        return ""        
