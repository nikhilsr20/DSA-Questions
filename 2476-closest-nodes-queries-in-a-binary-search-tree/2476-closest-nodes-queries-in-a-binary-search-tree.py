# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

import bisect
class Solution:
    def find(self,root,arr):
        if root is None:
            return
        
        self.find(root.left,arr)
        arr.append(root.val)
        self.find(root.right,arr)    


    def closestNodes(self, root: Optional[TreeNode], queries: List[int]) -> List[List[int]]:
        ans=[]
        arr=[]
        
        self.find(root,arr)
        
        for i in queries:
            x=bisect.bisect_left(arr,i)
            y=bisect.bisect_right(arr,i)
            if y>=len(arr):
                y=y-1
            if x>=len(arr):
                x=x-1
           
            p=-1
            if arr[x]<=i:
                p=arr[x]
            if x>0 and arr[x-1]<=i and arr[x-1]>p:
                p=arr[x-1]

            if x<len(arr)-1 and arr[x+1]<=i and arr[x+1]>p:
                p=arr[x+1] 
            q=-1
            if arr[y]>=i:
                q=arr[y]

            if y>0 and arr[y-1]>=i and arr[y-1]<q:
                q=arr[y-1] 

            if y<len(arr)-1 and arr[y+1]>=i and arr[y+1]<q:
                q=arr[y+1]     


            ans.append([p,q])

        
            

                     
            

           

        return ans    