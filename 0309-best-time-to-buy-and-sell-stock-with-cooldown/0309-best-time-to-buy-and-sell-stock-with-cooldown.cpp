

int find(vector<int> &prices,int i,int stock,vector<vector<int>> &dp){
  
for(int i=1;i<=prices.size();i++){
    for(int j=1;j<4;j++){
        int x=0;
        if(j==1){
          x=dp[i-1][j-1]-prices[i-1];
        }
        else if(j==2){
          x=dp[i-1][j-1]+prices[i-1];
        }
        else if(j==3){
          x=dp[i-1][j-1];
        }
      
        dp[i][j]=max(x, dp[i-1][j]);
    }
}
return dp[prices.size()][3];





}



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //tabulation
        vector<vector<int>> dp(prices.size()+1,vector<int> (4,0));
        int stock=0;
        return find(prices,0,stock,dp);
    

    }

    
};