class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;

        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                
                   int x = (nums[i] + nums[i+1] - 1) / nums[i+1]; 

                    ans+=x-1;
                    x=nums[i]/x;
                    nums[i]=x;
                
            }
        }
        return ans;
    }
};