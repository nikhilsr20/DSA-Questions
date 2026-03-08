def isprime(x):
    if x==1:
        return False
    for i in range(2,x):
        if x%i==0:
            return False
    return True        

class Solution:
    def checkPrimeFrequency(self, nums: List[int]) -> bool:
        map={}
        for i in nums:
            map[i]=map.get(i,0)+1
            

        for key,value in map.items():
            if isprime(value):
                return True

        return False              

