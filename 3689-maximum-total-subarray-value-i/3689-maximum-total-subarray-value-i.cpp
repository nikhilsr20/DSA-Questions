class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long m=INT_MIN;
        long long mi=INT_MAX;
        for(int i=0;i<nums.size();i++){
            m=max((long long)nums[i],m);
            mi=min((long long)nums[i],mi);
        }
        return k*(m-mi);
    }
};