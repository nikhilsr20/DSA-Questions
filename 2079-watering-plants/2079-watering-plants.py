class Solution:
    def wateringPlants(self, plants: List[int], capacity: int) -> int:
        c=capacity
        ans=0
        j=0
        for i in plants:
           
            if capacity>=i:
                ans+=1
                capacity-=i
            else:
                ans+=((2*j)+1)
                capacity=c
                capacity-=i

            j+=1    

        return ans    



        