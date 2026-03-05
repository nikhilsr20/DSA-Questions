int find(string &word1,string &word2,vector<vector<int>> &dp,int i,int j){
    if(i==word1.size() || j==word2.size()){
 
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    int x=find(word1,word2,dp,i+1,j);
    int y=find(word1,word2,dp,i,j+1);
    int z=0;
    if(word1[i]==word2[j]){
    z=find(word1,word2,dp,i+1,j+1)+1;
    }
    return dp[i][j]=max({x,y,z});
    
}
class Solution {
public:
    int minDistance(string word1, string word2) {
        // memoizatiom
        vector<vector<int>> dp(word1.size(),vector<int> (word2.size(),-1));
        int i=0;
        int j=0;
        int n=word1.size();
        int m=word2.size();

        return (n+m)-(2*find(word1,word2,dp,i,j));

    }
};