// int find(int amount,vector<int> &coins,int i,long long currsum,vector<vector<int>> &dp){
//     if(currsum>amount) return INT_MAX;
//     if(i==coins.size()){
//          if(currsum==amount){
           
//             return 0;
//          }
//          return INT_MAX;
//     }

//     if(dp[i][currsum]!=-1){
//         return dp[i][currsum];
//     }

//     int x=find(amount,coins,i+1,currsum,dp);
//     int y=find(amount,coins,i,currsum+coins[i],dp);
//     if(y!=INT_MAX){
//         y++;
//     }
//     return dp[i][currsum]=min(x,y);
// }

int find(int amount,vector<int> &coins,int i,long long currsum,vector<vector<int>> &dp){
    for(int i = 0; i <= coins.size(); i++){
    dp[i][0] = 0;
}
    

    for(int i=1;i<=coins.size();i++){
        for(int j=1;j<=amount;j++){
            // skip 
            int x=dp[i-1][j];

            // take
            int y=INT_MAX;
            if(j-coins[i-1]>=0){

            
            y=(dp[i][j-coins[i-1]]);
            if(y!=INT_MAX){
                y++;
            }
            }

            dp[i][j]=min(x,y);
            // cout<<"dp["<<i<<"]"<<"["<<j<<"]="<<dp[i][j]<<endl;

        }
    }

        return dp[coins.size()][amount];
}



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    //  memoization
    int ans=INT_MAX;
    vector<vector<int>> dp(coins.size()+1,vector<int> (amount+1,INT_MAX));
     ans=find(amount,coins,0,0,dp);
     return (ans==INT_MAX)?-1:ans;
    }
};