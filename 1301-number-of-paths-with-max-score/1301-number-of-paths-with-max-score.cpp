const int MOD=1000000007;
int find(int i,int j,vector<string>& board,vector<vector<int>> &dp){
    if(i==0 && j==0){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }


    // up
     long long p = -1e9; 
    if(i-1>=0 && board[i-1][j]!='X'){
       long long q=find(i-1,j,board,dp); 
       if(board[i][j]!='S'){
        q+=(board[i][j]-'0');
       }
       p=max(p,q);
    }
    // left
    if(j-1>=0 && board[i][j-1]!='X'){
       long long q=find(i,j-1,board,dp); 
        if(board[i][j]!='S'){
        q+=(board[i][j]-'0');
       }
       p=max(p,q);
    }

    // up left 
    if(j-1>=0 && i-1>=0 && board[i-1][j-1]!='X'){
       long long q=find(i-1,j-1,board,dp); 
        if(board[i][j]!='S'){
        q+=(board[i][j]-'0');
       }
       p=max(p,q);
    }
    return dp[i][j]=p%(MOD);


}
int find2(int i,int j,int sum,int &high,vector<string>& board,vector<vector<vector<int>>> &dp2){
    if(i==0 && j==0){
        if(sum==high){
            return 1;
        }
        return 0;
    }

    if(dp2[i][j][sum]!=-1){
        return dp2[i][j][sum];
    }


    // up
     long long p = 0; 
    if(i-1>=0 && board[i-1][j]!='X'){
        if(board[i][j]!='S'){
         p+=find2(i-1,j,sum+(board[i][j]-'0'),high,board,dp2); 
       
       }
       else{
         p+=find2(i-1,j,sum,high,board,dp2); 
       }
      
      
    }
    // left
    if(j-1>=0 && board[i][j-1]!='X'){
        if(board[i][j]!='S'){
         p+=find2(i,j-1,sum+(board[i][j]-'0'),high,board,dp2); 
       
       }
       else{
         p+=find2(i,j-1,sum,high,board,dp2); 
       }
    }

    // up left 
    if(j-1>=0 && i-1>=0 && board[i-1][j-1]!='X'){
        if(board[i][j]!='S'){
         p+=find2(i-1,j-1,sum+(board[i][j]-'0'),high,board,dp2); 
       
       }
       else{
         p+=find2(i-1,j-1,sum,high,board,dp2); 
       }
    }

    return dp2[i][j][sum]=p%MOD;


}


class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        vector<vector<int>> dp(board.size(),vector<int> (board[0].size(),-1));
        int x=board.size()-1;
        int y=board[0].size()-1;
        int high=find(x,y,board,dp);
        vector<vector<vector<int>>> dp2(board.size(),vector<vector<int>> (board[0].size(),vector<int> (9001,-1)));
        // cout<<high<<endl;
        if(high<0){
            high=0;
        }

        int freq=find2(x,y,0,high,board,dp2);

        return {high,freq};

    }
};