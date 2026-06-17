class Solution:
    def scoreDifference(self, nums: List[int]) -> int:
        a=0
        b=0
        chance=True
        for i in range(0,len(nums)):
            if (i+1)%6==0:
                chance=not chance

            if nums[i]%2==1:
                chance=not chance


            if chance:
                a+=nums[i]    
            else:
                b+=nums[i]

        return a-b        
        