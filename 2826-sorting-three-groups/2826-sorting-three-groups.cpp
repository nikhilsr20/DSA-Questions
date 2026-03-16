class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(4,0));
        for (int i = 1; i < nums.size()+1; i++) {
           
            for (int j = 1; j < 4; j++) {
               int best = 0;
                
                // previous states k <= j
                for(int k = 1; k <= j; k++){
                    best = max(best, dp[i-1][k]);
                }

                dp[i][j] = best + (nums[i-1] == j);
            }
        
        }
        int n=nums.size();
        return n-max({dp[n][1],dp[n][2],dp[n][3]});
    }
};