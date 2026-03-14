const int MOD=1000000007;



int find(vector<int> &group,int &n,long long i,int &m,vector<int> &profit,long long g,long long sum, unordered_map<long long,long long> &dp,vector<long long> &prefix){
    if(g>n){
        return 0;
    }

  
    if(i==profit.size()){
         if(m<=sum){
           return 1;
        }
        return 0;
    }
    if(sum + prefix[i] < (long long)m){
          return 0;
       }
    sum = min(sum, (long long)m);
    long long key= ((i<<55)  | (g<<45) | sum);
    if(dp.count(key)){
        return dp[key];
    }

long long x=find(group,n,i+1,m,profit,g+group[i],sum+profit[i],dp,prefix);
long long y=find(group,n,i+1,m,profit,g,sum,dp,prefix);
return dp[key]=(x+y)%MOD;
}


class Solution {
public:
    int profitableSchemes(int n, int m, vector<int>& group, vector<int>& profit) {
        //  recursive
        int s=accumulate(profit.begin(),profit.end(),0);
       
        unordered_map<long long,long long> dp;
        long long sum=0;

        vector<long long> prefix(profit.size(),0);
        long long add=0;
        for(int i=profit.size()-1;i>=0;i--){
            add+=profit[i];
            prefix[i]=add;
        }
      
        
        return find(group,n,0,m,profit,0,sum,dp,prefix);
 
    }
};