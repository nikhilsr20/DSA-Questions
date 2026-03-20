int find(int &n,int sum,vector<int> &dp){
 
if(sum==n){
  
    return 1;
}
if(dp[sum]!=-1){
    return dp[sum];
}
int x=INT_MIN;



    for(int i=1;i<=(n-sum);i++){
    x=max(find(n,sum+i,dp)*i,x);
}



return dp[sum]=x;





}


class Solution {
public:
    int integerBreak(int n) {
        // Memoization
          if(n==2 ) return 1;
          if(n==3) return 2;
         int sum=0;
         vector<int> dp(n+2,-1);
              return find(n,sum,dp);
        
        
    }
};