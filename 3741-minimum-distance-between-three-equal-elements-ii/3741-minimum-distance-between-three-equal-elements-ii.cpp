class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=INT_MAX;
        unordered_map<int,int> a;
        unordered_map<int,int> b;
        unordered_map<int,int> c;
        for(int i=0;i<nums.size();i++){
            if(a[nums[i]]==0){
                  a[nums[i]]=i+1;
            }
            else{
                if(b[nums[i]]==0){
                     b[nums[i]]=i+1;
                }
                else {
                    if(c[nums[i]]==0){
                        int x=(i+1)-a[nums[i]];
                        int y=(i+1)-b[nums[i]];
                        int z=b[nums[i]]-a[nums[i]];
                          ans=min(ans,x+y+z);

                          a[nums[i]]=b[nums[i]];
                          b[nums[i]]=i+1;
                    }
                }
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};