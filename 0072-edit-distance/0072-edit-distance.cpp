// int find(string &w1,string &w2,int i,int j,vector<vector<int>> &dp){
//     if(i == w1.size()){
//             return (int)w2.size() - j;
//         }
//         if(j == w2.size()){
            
//             return (int)w1.size() - i;
//         }

//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
        
//         int x=INT_MAX;
//         int y=INT_MAX;
//         int z=INT_MAX;

//         if(w1[i] == w2[j]){
//             x=find(w1, w2, i+1, j+1, dp);
//         }
//         else{
//             // Insert
//             x=find(w1, w2, i, j+1, dp)+1;
            
//             // Delete
//             y=find(w1, w2, i+1, j, dp)+1;
            
//             // Replace
//             z=find(w1, w2, i+1, j+1,dp)+1;
//         }
//         return dp[i][j]=min({x,y,z});

// }


 int find(string &w1,string &w2,vector<vector<int>> &dp){
 for(int i=0;i<=w1.size();i++) dp[i][0] = i;
        for(int j=0;j<=w2.size();j++) dp[0][j] = j;

 for(int i=1;i<=w1.size();i++){
    for(int j=1;j<=w2.size();j++){
         int x=INT_MAX;
        int y=INT_MAX;
        int z=INT_MAX;
        if(w1[i-1]==w2[j-1]){
             x=dp[i-1][j-1];
        }
        else{
            x=dp[i][j-1]+1;
            y=dp[i-1][j-1]+1;
            z=dp[i-1][j]+1;
        }
        dp[i][j]=min({x,y,z});
    }
 }
 return dp[w1.size()][w2.size()];


 





 }



class Solution {
public:
    int minDistance(string word1, string word2) {
        // tabulation
        vector<vector<int>> dp(word1.size()+1,vector<int> (word2.size()+1,0));

        return find(word1,word2,dp);

    }
};