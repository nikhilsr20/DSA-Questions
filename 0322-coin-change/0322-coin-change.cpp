int find(int amount,vector<int> &coins,int i,long long currsum,vector<vector<int>> &dp){
    if(currsum>amount) return INT_MAX;
    if(i==coins.size()){
         if(currsum==amount){
           
            return 0;
         }
         return INT_MAX;
    }

    if(dp[i][currsum]!=-1){
        return dp[i][currsum];
    }

    int x=find(amount,coins,i+1,currsum,dp);
    int y=find(amount,coins,i,currsum+coins[i],dp);
    if(y!=INT_MAX){
        y++;
    }
    return dp[i][currsum]=min(x,y);
}



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    //  memoization
    int ans=INT_MAX;
    vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
     ans=find(amount,coins,0,0,dp);
     return (ans==INT_MAX)?-1:ans;
    }
};