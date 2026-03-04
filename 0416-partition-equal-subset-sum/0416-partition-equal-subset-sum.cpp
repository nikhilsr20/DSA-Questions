int find(int &need,int curr,vector<int> &nums,int i,vector<vector<int>> &dp){
    if(curr>need){
        return 0;
    }
    if(i==nums.size()){
        if(curr==need){
            return 1;
        }
        return 0;
    }

    if(dp[i][curr]!=-1){
        return dp[i][curr];
    }
    int x=find(need,curr+nums[i],nums,i+1,dp);
    int y=find(need,curr,nums,i+1,dp);
    
    return dp[i][curr]=x|y;

}
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Memoization
    int sum=accumulate(nums.begin(),nums.end(),0);

    int need=sum/2;
    if(sum%2==1){
        return false;
    }
    // bool ans=false;
    vector<vector<int>> dp(nums.size(),vector<int> (need+1,-1));
    int p=find(need,0,nums,0,dp);
    return p;



         
    }
};