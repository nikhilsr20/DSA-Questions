int find(string &w1,string &w2,int i,int j,vector<vector<int>> &dp){
    if(i == w1.size()){
            return (int)w2.size() - j;
        }
        if(j == w2.size()){
            
            return (int)w1.size() - i;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int x=INT_MAX;
        int y=INT_MAX;
        int z=INT_MAX;

        if(w1[i] == w2[j]){
            x=find(w1, w2, i+1, j+1, dp);
        }
        else{
            // Insert
            x=find(w1, w2, i, j+1, dp)+1;
            
            // Delete
            y=find(w1, w2, i+1, j, dp)+1;
            
            // Replace
            z=find(w1, w2, i+1, j+1,dp)+1;
        }
        return dp[i][j]=min({x,y,z});

}



class Solution {
public:
    int minDistance(string word1, string word2) {
        // rmenoization
        vector<vector<int>> dp(word1.size(),vector<int> (word2.size(),-1));

        return find(word1,word2,0,0,dp);

    }
};