class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,int> a;
        unordered_map<int,int> b;
        unordered_map<int,int> c;
        unordered_map<int,int> d;
        vector<int> ans(queries.size(),INT_MAX);

        for(int i=nums.size()-1;i>=0;i--){
             if (a[nums[i]]==0){
                a[nums[i]]=i+1;
             }
        }
         for(int i=0;i<nums.size();i++){
             if (d[nums[i]]==0){
                d[nums[i]]=i+1;
             }
        }

        for(int i=0;i<queries.size();i++){
            c[queries[i]]=i+1;
        }
        
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(c[i]!=0){
                if(i+1 != a[nums[i]]){
               ans[c[i] - 1] = min(ans[c[i] - 1],(i+1)+(n-a[nums[i]]+1)-1);
              
                }
                if(b[nums[i]]!=0){
                    ans[c[i]-1]=min(ans[c[i]-1],i-(b[nums[i]]-1));
                  
                }
            }
            b[nums[i]]=i+1;
        }
        b.clear();
        for(int i=nums.size()-1;i>=0;i--){
            if(c[i]!=0){
                if(i+1 != d[nums[i]]){
               ans[c[i] - 1] = min(ans[c[i] - 1], (n - (i) + d[nums[i]])-1);
                }
                if(b[nums[i]]!=0){
                    ans[c[i]-1]=min(ans[c[i]-1],(b[nums[i]]-1)-i);
                }
            }
              b[nums[i]]=i+1;
        }

        for(int i=0;i<ans.size();i++){
            if(ans[i]==INT_MAX)
            ans[i]=-1;
        }
        return ans;
    }
};