class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        p=[[ 0 for _ in range(2)] for i in range(0,len(strs))]
        for i in range(0,len(strs)):
            q=strs[i]
            q=''.join(sorted(q))
            p[i][0]=q
            p[i][1]=i

        p.sort(key=lambda x: x[0])

        ans=[[]]   

        ans[0].append(strs[p[0][1]])

        for i in range(1,len(p)):
            if p[i][0] == p[i-1][0]:
               ans[len(ans)-1].append(strs[p[i][1]])
            else:
                ans.append([])
                ans[len(ans)-1].append(strs[p[i][1]])

        return ans        



        
        
        