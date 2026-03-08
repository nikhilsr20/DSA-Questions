class Solution:
    def partitionArray(self, nums: List[int], k: int) -> bool:
        if len(nums)/k != int(len(nums)/k):
            return False

        dic={}
        x=len(nums)/k
        for i in nums:
            dic[i]=dic.get(i,0)+1

        for key,value in dic.items():
            if value>x:
                return False
        return True           


