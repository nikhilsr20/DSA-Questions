import heapq
class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        heapq.heapify(nums)
        ans=[]
        while nums:
            a=heapq.heappop(nums)
            b=heapq.heappop(nums)

            ans.append(b)
            ans.append(a)


        return ans        
