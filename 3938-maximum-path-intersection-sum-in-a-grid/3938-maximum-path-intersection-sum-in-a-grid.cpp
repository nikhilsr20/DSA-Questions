


class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {

        int ans=INT_MIN;
        for(int i=0;i<grid.size();i++){
            int count=0;
            int x=0;
             for(int j=0;j<grid[0].size();j++){
              count+=grid[i][j];
              x++;
                 

              if(x==1){
                int p=-100000,q=-100000;
                if(j-1>=0){
                    p=grid[i][j-1];
                }
                if(j+1<grid[0].size()){
                    q=grid[i][j+1];
                }

                ans = max(ans, max(count+p, count+q));
              }   
              else{
              ans=max(ans,count);
              }

              count=max(0,count);
              if(count==0){
                  x=0;
              }

        }
        }
        for(int i=0;i<grid[0].size();i++){
            int count=0;
            int x=0;
             for(int j=0;j<grid.size();j++){
              count+=grid[j][i];
              x++;
              if(x==1){
           
                int p=-100000,q=-100000;
                if(j-1>=0){
                    p=grid[j-1][i];
                }
                if(j+1<grid.size()){
                    q=grid[j+1][i];
                }

                ans = max(ans, max(count+p, count+q));
              }   
              else{
              ans=max(ans,count);
              }

              count=max(0,count);
              if(count==0){
                  x=0;
              }



        }
        }

        for(int i=1;i<grid.size()-1;i++){
     
             for(int j=1;j<grid[0].size()-1;j++){
              

                ans = max(ans, grid[i][j]);
              
              }

              

        }




        return ans;



        
    }
};