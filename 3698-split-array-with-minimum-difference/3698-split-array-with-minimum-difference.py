class Solution:
    def splitArray(self, nums: List[int]) -> int:
        p=[-1]*len(nums)
        pmin=nums[len(nums)-1]
        q=[-1]*len(nums)
        p[len(nums)-1]=nums[len(nums)-1]
        q[0]=nums[0]
        qmin=nums[0]

        if len(nums)==2 :
            return abs(nums[0]-nums[1])




        for i in range(len(nums)-2,-1,-1):
            pmin+=nums[i]
            if nums[i]>nums[i+1]:
                print(pmin,i)
                p[i]=pmin
            else:
                break  

        for i in range(1,len(nums)):
            if nums[i]>nums[i-1]:
                qmin+=nums[i]
                print(qmin)
                q[i]=qmin
            else:
                break


        ans=float("inf")
        for i in range(0,len(nums)-1):
            if p[i+1]!=-1 and q[i]!=-1:
        
                ans=min(ans,abs(p[i+1]-q[i]))

            


              
        if ans==float("inf"):
            return -1

        return ans     


