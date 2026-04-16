class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        count=0
        ans=[]
        for i in range(1,k):
            if nums[i]>nums[i-1] and nums[i]-nums[i-1]==1:
                count=count+1
            else:
                count=count-1

        if k-count==1:
            ans.append(nums[k-1])
        else:
            ans.append(-1)    
        i=k    
        while i<len(nums):
            if nums[i-k+1]>nums[i-k] and nums[i-k+1]-nums[i-k]==1:
                count=count-1
            else:
                count=count+1


            if nums[i]>nums[i-1] and nums[i]-nums[i-1]==1:
                count=count+1
            else:
                count=count-1
            
            if k-count==1:
                ans.append(nums[i])
            else:
                ans.append(-1)                 
             
            i=i+1   

        return ans         
