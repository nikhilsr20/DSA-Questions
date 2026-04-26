void find(bool &ans,int x,int y,int i,int j, vector<vector<bool>> &visit,vector<vector<char>>& grid){
    if(ans){
        return;
    }
    if(visit[i][j]==true){
        ans=true;
        return;
    }
    visit[i][j]=true;

    if(x==-1 && y==-1){
        if(i+1<grid.size() && grid[i+1][j]==grid[i][j]){
           find(ans,i,j,i+1,j,visit,grid);
        }
        if(j+1<grid[0].size() && grid[i][j+1]==grid[i][j]){
           find(ans,i,j,i,j+1,visit,grid);
        }
        if(i-1>=0 && grid[i-1][j]==grid[i][j]){
           find(ans,i,j,i-1,j,visit,grid);
        }
        if(j-1>=0 && grid[i][j-1]==grid[i][j]){
           find(ans,i,j,i,j-1,visit,grid);
        }
    }
    else{
        if(i+1<grid.size() && grid[i+1][j]==grid[i][j] && !(x==i+1 && y==j)){
           find(ans,i,j,i+1,j,visit,grid);
        }
        if(j+1<grid[0].size() && grid[i][j+1]==grid[i][j] && !(x==i && y==j+1)){
           find(ans,i,j,i,j+1,visit,grid);
        }
        if(i-1>=0 && grid[i-1][j]==grid[i][j] && !(x==i-1 && y==j)){
           find(ans,i,j,i-1,j,visit,grid);
        }
        if(j-1>=0 && grid[i][j-1]==grid[i][j]&& !(x==i && y==j-1) ){
           find(ans,i,j,i,j-1,visit,grid);
        }
    }
}


class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visit(n,vector<bool> (m,false));

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                
                if(visit[i][j]==false){
                    
                bool ans=false;

                  find(ans,-1,-1,i,j,visit,grid);

                  if(ans){
                    return true;
                  }
                }
        }
        }
        return false;

    }
};