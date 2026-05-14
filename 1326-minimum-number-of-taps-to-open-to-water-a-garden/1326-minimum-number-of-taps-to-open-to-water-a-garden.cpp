// int find(int i,vector<vector<int>> &interval,int maxi,vector<vector<int>> &dp,int &n){
//     // cout<<"run5"<<i<<"--"<<maxi<<endl;
//     if(i==interval.size()){
//        if(maxi != -1 && interval[maxi][1] >= n){
//             return 0;
//         }
//         return 1000000;
//     }

//     if(dp[maxi+1][i]!=-1){
//         return dp[maxi+1][i];
//     }
     
//     int x=1000000,y=1000000;
//     if(maxi==-1){
//         if(interval[i][0]==0){
//          x=find(i+1,interval,i,dp,n)+1;
//         }
//     }
//     else if(interval[maxi][1]>=interval[i][0]){
        
//         int l=interval[maxi][1];
//         int m=interval[i][1];
//         if(l<m){
//            x=find(i+1,interval,i,dp,n)+1;
//         }
//         else{
//              x=find(i+1,interval,maxi,dp,n)+1;
//         }
     
//     }
//      y=find(i+1,interval,maxi,dp,n);

//      return dp[maxi+1][i]=min(x,y);


// }

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> interval;
        
        for(int i=0;i<ranges.size();i++){
            int x=i-ranges[i];
            int 
            y=i+ranges[i];

            interval.push_back({max(x,0),min(y,n)});
          
        
        }
         

        sort(interval.begin(),interval.end()); 

        vector<int> ans(n+1,INT_MAX);
        if(interval[0][0]!=0){
            return -1;
        }
        ans[0]=0;
        for(int i=0;i<interval.size();i++){
              int x=interval[i][0];
              int y=interval[i][1];
               
              if(ans[x]!=INT_MAX){
                 int c=ans[x]+1;

                 for(int j=x;j<=y;j++){
                    
                    ans[j]=min(c,ans[j]);
                 }
              }
              else{
                return -1;
              }
        }
        if(ans[n]==INT_MAX){
            return -1;
        }
        return ans[n];


         
     
    
        

   


    }

};