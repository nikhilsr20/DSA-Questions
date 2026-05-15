int find(int i,int j,string &s,string &t,vector<vector<int>> &dp){
    if(i==s.size() || j==t.size()){
        if(j==t.size()){
            return 1;
        }
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    //    if match
    int x=0,y=0;
    if(s[i]==t[j]){
        x+=find(i+1,j+1,s,t,dp);
    }

    // skip
       y+=find(i+1,j,s,t,dp);
       return dp[i][j]=x+y;
    
}



class Solution {
public:
    int numDistinct(string s, string t) {
        // dp
        vector<vector<int>> dp(s.size(),vector<int> (t.size(),-1));
        return find(0,0,s,t,dp);

  
    }
};