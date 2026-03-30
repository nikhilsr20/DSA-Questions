class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        a={}
        for i in nums:
            a[i]=a.get(i,0)+1

        b = dict(sorted(a.items(), key=lambda x: (x[1], -x[0]))) 
        j=0
        for key,value in b.items():

            for i in range(0,value):
                nums[j]=key
                j=j+1

        return nums        
           



