class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans=10000;
       
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target && ans>abs(i-start)){
               ans= abs(i-start);
                
            }
        }
        return ans;
    }
};