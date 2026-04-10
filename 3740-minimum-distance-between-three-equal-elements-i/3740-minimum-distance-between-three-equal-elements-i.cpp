class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=1;i<nums.size();i++){
            int l=i+1;
            int m=i-1;
            while(l<nums.size() && nums[l]!=nums[i]){
                l++;
            }
            while(m>=0 && nums[m]!=nums[i]){
                
                m--;
            }

            if(m<0 || l==nums.size()){
                continue;
            }
            int x=l-m;
            int y=l-i;
            int z=i-m;
           

            ans=min(ans,x+y+z);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};