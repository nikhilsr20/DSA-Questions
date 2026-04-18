class Solution:
    def mirrorDistance(self, n: int) -> int:
        s=str(n)
        s = ''.join(reversed(s))
        p=int(s)
        return abs(n-p)