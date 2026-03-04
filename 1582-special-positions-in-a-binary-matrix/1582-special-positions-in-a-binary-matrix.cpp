class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
               row[j]++;
                }
           }
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
               col[i]++;
                }
           }
        }
        int count=0;

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1 && row[j]<2 && col[i]<2){
                   count++;
                }
           }
        }
        return count;
       

        
    }
};