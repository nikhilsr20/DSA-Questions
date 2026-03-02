class Solution {
public:
    bool validPartition(vector<int>& a) {
       vector<bool> dp(a.size()+1,false);
       dp[0]=true;
       dp[1]=false;
       for(int i=1;i<a.size();i++){
              int j=i+1;
              bool x=false,y=false,z=false;
              if(a[i]==a[i-1]){
                x=dp[j-2]&true;
              }
              if(i>=2 && a[i]==a[i-1] && a[i-1]==a[i-2]){
                y=dp[j-3]&true;
              }
              if(i>=2 && a[i]-a[i-1]==1 && a[i-1]-a[i-2]==1){
                z=dp[j-3]&true;
              }
            //   cout<<x<<y<<z<<endl;
              dp[j]=x|y|z;
              cout<<dp[j]<<endl;
       }
       return dp[a.size()];
    }
};