int find(vector<vector<int>> &g,int i, int j,vector<vector<int>> &dp){
    if(i>=g.size() || j >= g[0].size() || i<0 || j<0){
        return 0;
    }
     if(g[i][j] == 1)
        return 0;
    if(i==g.size()-1 && j==g[0].size()-1){
     
        return 1;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }


    
        int x=find(g,i+1,j,dp);
        int y=find(g,i,j+1,dp);
        return dp[i][j]+=(x+y);
     

    
}
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        // Memoization
       vector<vector<int>> dp(g.size(),vector<int> (g[0].size(),0));
        return find(g,0,0,dp);
       
        
    }
};