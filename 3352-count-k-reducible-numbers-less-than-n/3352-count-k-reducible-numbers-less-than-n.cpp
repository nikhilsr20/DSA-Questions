int dp2[801][2][801];
const int MOD=1000000007;
long long find(int pos,int tight,int ones,string &s,int &k, vector<int> &dp){
    if(pos == s.size()){

    if(ones == 0) return 0;

    if(ones == 1) return 1;

    return (dp[ones] + 1 <= k);
}

    if(dp2[pos][tight][ones]!=-1){
        return dp2[pos][tight][ones];
    }

   long long x=0;

    if(tight==1){
        if(s[pos]=='0'){
        x+=find(pos+1,1,ones,s,k,dp);
        }
        else{
        x+=find(pos+1,0,ones,s,k,dp);
        x+=find(pos+1,1,ones+1,s,k,dp);
        }
    }
    else {
        x+=find(pos+1,0,ones,s,k,dp);
        x+=find(pos+1,0,ones+1,s,k,dp);
    }

    return dp2[pos][tight][ones]=x%MOD;


}

class Solution {
public:
    int countKReducibleNumbers(string s, int k) {
        vector<int> dp(802,0);
        dp[1]=0;
        dp[2]=1;

        for(int i=3;i<=800;i++){
        int count = __builtin_popcount(i);
            dp[i]=dp[count]+1;
        }

        memset(dp2,-1,sizeof(dp2));

    int ans= find(0,1,0,s,k,dp)%MOD;
    int ones = 0;

for(char c : s){
    if(c=='1') ones++;
}
    if(dp[ones]+1<=k){
    ans--;
    }
return ans;


        


        

    }
};