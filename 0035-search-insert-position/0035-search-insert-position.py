import bisect
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        a=bisect_left(nums,target)
        return a
        