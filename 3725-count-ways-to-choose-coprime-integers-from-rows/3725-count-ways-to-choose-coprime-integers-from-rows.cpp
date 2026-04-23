const int MOD=1000000007;

int find(int i,vector<vector<int>> &mat, vector<vector<int>> &dp,int gcd){
    if(i==mat.size()){
        if(gcd==1){
            return 1;
        }
        return 0;
    }
    if(dp[i][gcd+1]!=-1){
        return dp[i][gcd+1];
    }

    long long c=0;
    for(int j=0;j<mat[i].size();j++){

    if(gcd==-1){
        c+=find(i+1,mat,dp,mat[i][j]);
    }
    else{
        c+=find(i+1,mat,dp,__gcd(gcd,mat[i][j]));
    }

    }

    return dp[i][gcd+1]=c%MOD;


}


class Solution {
public:
    int countCoprime(vector<vector<int>>& mat) {
        // recursive
        int count=0;
        int gcd=-1;
        vector<vector<int>> dp(151,vector<int> (152,-1));
        return find(0,mat,dp,gcd)%MOD;
    
    }
};