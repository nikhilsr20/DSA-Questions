class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(1001, 1));
        int m = 0;
        for (int i = 0; i < nums.size(); i++) {

            for (int j = 0; j < i; j++) {
                

                int diff=nums[i]-nums[j]+500;
                dp[i][diff]=max(dp[i][diff],dp[j][diff]+1);
                m=max(dp[i][diff],m);


                
            }
        }
        return m;
    }
};