// int find(string &word1,string &word2,vector<vector<int>> &dp,int i,int j){
//     if(i==word1.size() || j==word2.size()){
//         return 0;
//     }

//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
    
//     int x=find(word1,word2,dp,i+1,j);
//     int y=find(word1,word2,dp,i,j+1);
//     int z=0;
//     if(word1[i]==word2[j]){
//     z=find(word1,word2,dp,i+1,j+1)+1;
//     }
//     return dp[i][j]=max({x,y,z});
    
// }

 int find(string &word1,string &word2,vector<vector<int>> &dp){

    for(int i=1;i<=word1.size();i++){
        for(int j=1;j<=word2.size();j++){
            int x=dp[i-1][j];
            int y=dp[i][j-1];

            int z=0;
            if(word1[i-1]==word2[j-1]){
                z=dp[i-1][j-1]+1;
            }
            dp[i][j]=max({x,y,z});
        }
    }

    return dp[word1.size()][word2.size()];









 }


class Solution {
public:
    int minDistance(string word1, string word2) {
        // tabulation
        vector<vector<int>> dp(word1.size()+1,vector<int> (word2.size()+1,0));
        int i=0;
        int j=0;
        int n=word1.size();
        int m=word2.size();

        return (n+m)-(2*find(word1,word2,dp));

    }
};