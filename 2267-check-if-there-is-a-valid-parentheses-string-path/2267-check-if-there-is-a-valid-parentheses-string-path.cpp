bool find(vector<vector<char>> &grid,int i,int j,int count,vector<vector<vector<int>>> &dp){
    if(count>5000){
        return false;
    }
   
    if(i==grid.size()-1 && j==grid[0].size()-1){
        if(count==0){
            return true;
        }
        return false;
    }

    if(dp[i][j][count]!=-1){
        return dp[i][j][count];
    }
    
     int x=false,y=false;
    if(i+1<grid.size()){
        if(grid[i+1][j]==')' && count>0){
        x=find(grid,i+1,j,count-1,dp);
        }
        else if (grid[i+1][j]=='(' ){
            x=find(grid,i+1,j,count+1,dp);
        }
    }
    if(j+1<grid[0].size()){
        if(grid[i][j+1]==')' && count>0){
        y=find(grid,i,j+1,count-1,dp);
        }
        else if (grid[i][j+1]=='(' ){
            y=find(grid,i,j+1,count+1,dp);
        }
    }

    return dp[i][j][count]=x|y;

}


class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        if(grid[0][0]==')') return false;
        int x=(grid.size()*grid[0].size())/2+1;
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>> (grid[0].size(),vector<int> (x,-1)));
      int count=1;
        return find(grid,0,0,count,dp);
     
    }
};