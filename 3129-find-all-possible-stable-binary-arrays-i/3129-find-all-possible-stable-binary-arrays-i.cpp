int find(int x, int y, int zero, int one, int& limit,  vector<vector<vector<vector<int>>>> &dp) {
    if (zero == 0 && one == 0) {
        return 1;
    }


    if(dp[zero][one][x][y]!=-1){
        return dp[zero][one][x][y];
    }




    int z=0;
    int w=0;
    if (zero > 0) {
       if (y==0){
        z=find(0, 1, zero-1, one, limit,dp);
       }
       else if(x==0){
           if(y<limit){
            z=find(0, y+1, zero-1, one, limit,dp);
           }
       }
       else{
        z=find(0, 1, zero - 1, one, limit,dp);
       }
    }
    if (one > 0) {
        if (y==0){
        w=find(1, 1, zero, one-1, limit,dp);
       }
       else if(x==1){
           if(y<limit){
            w=find(1, y+1, zero, one-1, limit,dp);
           }
       }
       else{
        w=find(1, 1, zero, one-1, limit,dp);
       }
    }

    return dp[zero][one][x][y]=(z+w)%(1000000007);
}

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {

        int count = 0;
        vector<vector<vector<vector<int>>>> dp(zero+1,vector<vector<vector<int>>> (one+1,vector<vector<int>> (2,vector<int> (limit+1,-1))));
        return find(0, 0, zero, one, limit,dp);
 
    }
};