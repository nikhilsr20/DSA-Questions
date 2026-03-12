class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<int>> visit(grid.size(),vector<int> (grid[0].size(),INT_MAX));

        q.push({0,0});
        int ans=INT_MAX;
        visit[0][0]=1;

        if(grid[0][0]==1){
            return -1;
        }

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
           int x=visit[i][j]+1;
           q.pop();
            if(i-1>=0){
                 if(visit[i-1][j]==INT_MAX && grid[i-1][j]==0){
                    q.push({i-1,j});
                }
                if(grid[i-1][j]==0){
                    visit[i-1][j]=min(visit[i-1][j],x);
                   
                }
                
            }
            if(j-1>=0){
                 if(visit[i][j-1]==INT_MAX && grid[i][j-1]==0){
               q.push({i,j-1});
                
                }
                if( grid[i][j-1]==0){
                    visit[i][j-1]=min(visit[i][j-1],x);
                    
                }
                
            }
            if(i+1<grid.size() && grid[i+1][j]==0){
                if(visit[i+1][j]==INT_MAX){
                q.push({i+1,j});
                }
                if(grid[i+1][j]==0){
                    visit[i+1][j]=min(visit[i+1][j],x);
                    
                }
                
            }
            if(j+1<grid[0].size() && grid[i][j+1]==0){
                if(visit[i][j+1]==INT_MAX){
                q.push({i,j+1});
           
                }
                if( grid[i][j+1]==0){
                    visit[i][j+1]=min(visit[i][j+1],x);
                    
                }
                
            }

            if(i-1>=0 && j-1>=0 && grid[i-1][j-1]==0){
                if(visit[i-1][j-1]==INT_MAX){
                q.push({i-1,j-1});
               
                }
                if( grid[i-1][j-1]==0){
                    visit[i-1][j-1]=min(visit[i-1][j-1],x);
                    
                }
                
            }
            if(i-1>=0 && j+1<grid[0].size() && grid[i-1][j+1]==0){
                 if(visit[i-1][j+1]==INT_MAX){
                q.push({i-1,j+1});
                
                }
                if( grid[i-1][j+1]==0){
                    visit[i-1][j+1]=min(visit[i-1][j+1],x);
                   
                }
               
            }
            if(j-1>=0 && i+1<grid.size() && grid[i+1][j-1]==0){
                if(visit[i+1][j-1]==INT_MAX){
                q.push({i+1,j-1});
              
                }
            
                if( grid[i+1][j-1]==0){
                    visit[i+1][j-1]=min(visit[i+1][j-1],x);
                   
                }
                
            }
            if(i+1<grid.size() && j+1<grid[0].size() &&  grid[i+1][j+1]==0){
                if(visit[i+1][j+1]==INT_MAX){
                q.push({i+1,j+1});
                
                }
                if( grid[i+1][j+1]==0){
                    visit[i+1][j+1]=min(visit[i+1][j+1],x);
                }
                
            }


        }
        return visit[grid.size()-1][grid[0].size()-1]==INT_MAX ? -1 : visit[grid.size()-1][grid[0].size()-1];



    

    }
};