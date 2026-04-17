class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        a={}
        m=float("inf")
        for i in range(0,len(nums)):
            if a.get(nums[i],-1)!=-1:
                m=min(m,i-a.get(nums[i]))
               
            
            s=str(nums[i])
            s=''.join(reversed(s))
            k=int(s)

            a[k]=i
        if m==float("inf"):
            return -1    
        return m    

