class Solution:
    def nextGreaterElement(self, nums2: List[int], nums1: List[int]) -> List[int]:
        a={}
        st=[]
        for i in range(len(nums1)-1,-1,-1):
            while len(st)!=0 and st[-1]<nums1[i]:
                st.pop(-1)
            
            if len(st)==0:
                a[nums1[i]]=-1
            else:
                a[nums1[i]]=st[-1]

            st.append(nums1[i])    

        ans=[]
        for i in nums2:
            ans.append(a[i])

        return ans    



        