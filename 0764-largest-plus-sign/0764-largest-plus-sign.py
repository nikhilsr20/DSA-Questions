import copy
class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        a=[[1 for _ in range(n)] for _ in range(n)]
        m=0
        if len(mines)<(n*n):
            m=1

        for i,j in mines:
            a[i][j]=0

        l = copy.deepcopy(a)
        r = copy.deepcopy(a)
        u = copy.deepcopy(a)
        d = copy.deepcopy(a)


        for i in range(0,len(l)):
            count=0
            for j in range(0,len(l[0])):
               
                if l[i][j]==1:
                    count=count+1
                else:
                    count=0
                l[i][j]=count     
                # print(i, j ,"==",l[i][j]) 
                 
                

        for i in range(0,len(l)):
            count=0
            for j in range(len(l[0])-1,-1,-1):
                
                if r[i][j]==1:
                    count=count+1
                else:
                    count=0
                r[i][j]=count  
                 

        for j in range(0,len(l[0])):                     
            count=0
            for i in range(0,len(l)):
                if u[i][j]==1:
                    count=count+1
                else:
                    count=0
                u[i][j]=count 

        for j in range(0,len(l[0])):                     
            count=0
            for i in range(len(l)-1,-1,-1):
                if d[i][j]==1:
                    count=count+1
                else:
                    count=0
                d[i][j]=count

     

        for i in range(1,len(l)-1):
            for j in range(1,len(l[0])-1):
                # print(l[i][j-1],u[i-1][j],r[i][j+1],d[i+1][j])
                if a[i][j]==1:
                   m=max(m,min(l[i][j-1],u[i-1][j],r[i][j+1],d[i+1][j])+1)
              
        return m
                         