int find(vector<int> &prices,int i,int stock,vector<vector<int>> &dp){
    if(i==prices.size()){
        return 0;
    }

    if(dp[i][stock]!=-1){
        return dp[i][stock];
    }

    int x=0,y=0;

    if(stock==0){
        x=find(prices,i+1,1,dp)-prices[i];
    }
    else if(stock==1){
         x=find(prices,i+1,2,dp)+prices[i];
    }
    else{
         x=find(prices,i+1,0,dp);
    }
     y=find(prices,i+1,stock,dp);

     return dp[i][stock]=max(x,y);

}



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //memoization
        vector<vector<int>> dp(prices.size(),vector<int> (3,-1));
        int stock=0;
        return find(prices,0,stock,dp);
    

    }

    
};