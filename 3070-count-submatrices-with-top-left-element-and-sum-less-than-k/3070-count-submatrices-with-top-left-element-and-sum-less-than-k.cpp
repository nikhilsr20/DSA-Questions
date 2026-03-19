class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        for(int i=0;i<grid[0].size();i++){
            int sum=0;
            for(int j=0;j<grid.size();j++){
                 sum+=grid[j][i];
                 grid[j][i]=sum;
        }

        }

       for(int i=0;i<grid.size();i++){
            int sum=0;
            for(int j=0;j<grid[0].size();j++){
                 sum+=grid[i][j];
                 grid[i][j]=sum;
        }

        }
        int count=0;
        for(int i=0;i<grid.size();i++){
          
            for(int j=0;j<grid[0].size();j++){
                 if(grid[i][j]<=k){
                    count++;
                 }
        }

        }
        return count;
        

    }
};