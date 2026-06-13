class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        x=0
        count=0
        ans=0
        for i in nums:
            if i%2==0 and x==0:
                count+=1
                x=1
            elif i%2==1 and x==1:
                count+=1
                x=0

        ans=max(count,ans)

        x=1
        count=0
        for i in nums:
            if i%2==0 and x==0:
                count+=1
                x=1
            elif i%2==1 and x==1:
                count+=1
                x=0

        ans=max(count,ans)


        count=0

        for i in nums:
            if i%2==0:
                count+=1
        ans=max(count,ans)

  
        count=0
        
        for i in nums:
            if i%2==1:
                count+=1
        ans=max(count,ans)        
        return ans






        