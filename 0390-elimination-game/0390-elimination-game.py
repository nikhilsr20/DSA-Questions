class Solution:
    def lastRemaining(self, n: int) -> int:
        left=1
        right=n
        gap=1
        total=n
        pos=False

        while total!=1:
            if pos==False:
                if total%2==1:
                    left=left+gap
                    right=right-gap
                else:
                    left=left+gap
                pos=True    

            else:
                if total%2==1:
                    left=left+gap
                    right=right-gap
                else:
                    right=right-gap
                pos=False  

                

            gap=gap*2
            total=total//2

        if pos:
            return right

        return left    


        