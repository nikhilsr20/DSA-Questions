
int find(int &need,vector<int> &nums, vector<vector<int>> &dp){
    dp[0][0]=1;

    for(int i=0;i<nums.size();i++){
       
     for(int j=1;j<=need;j++){

       dp[i+1][j] = dp[i][j];  // not take

    if(j-nums[i] >= 0){
        dp[i+1][j] = dp[i+1][j] || dp[i][j-nums[i]]; // take
    }
    }
    }
    return dp[nums.size()][need];

    

}


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // tabulation
    int sum=accumulate(nums.begin(),nums.end(),0);

    int need=sum/2;
    if(sum%2==1){
        return false;
    }
    // bool ans=false;
      vector<vector<int>> dp(nums.size()+1,vector<int> (need+1,0));
    int p=find(need,nums,dp);

   

    return p;



         
    }
};