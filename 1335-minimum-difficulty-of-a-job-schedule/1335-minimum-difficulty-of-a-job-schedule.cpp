int find(vector<int> &a,int d,int i,int m,vector<vector<vector<int>>> &dp){
    if(d<0) return 1000000;

    if(i==a.size()){
        if(d==1){
        return max(m,a[i-1]);
        }
        
        
        return 1000000;
    }

    if(dp[i][d][m]!=-1){
        return dp[i][d][m];
    }

   
    int x=find(a,d,i+1,max(m,a[i]),dp);
    int y=find(a,d-1,i+1,a[i],dp)+m;


    return dp[i][d][m]=min(x,y);
    
    




}
class Solution {
public:
    int minDifficulty(vector<int>& a, int d) {
        if(d>a.size()){
            return -1;
        }
        vector<vector<vector<int>>> dp(301,vector<vector<int>> (11,vector<int> (1001,-1)));
      

        return find(a,d,1,a[0],dp);
   
    }
};