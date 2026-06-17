class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], m: int, k: int) -> int:
        a=[]
        mp={}
        for i in range(0,len(values)):
            a.append([values[i],labels[i]])

        a.sort(key=lambda x: x[0],reverse=True)

        count=0
        sum=0

        for x,y in a:

            if mp.get(y,0)<k:
                sum+=x
                count+=1
                mp[y]=mp.get(y,0)+1

            if count==m:
                break

        return sum           


