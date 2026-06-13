long long find(int i,int j,int k,vector<int> &nums1,vector<int> &nums2, vector<vector<vector<long long>>> &dp){
    if(k==0 || i==nums1.size() || j==nums2.size()){
        if(k==0){
        return 0;
        }
        return -100000000000000;
    }

    if(dp[i][j][k]!=1e15){
        return dp[i][j][k];
    }
     

    long long p=LLONG_MIN; 
    p=max(p,find(i+1,j+1,k-1,nums1,nums2,dp)+(1LL*nums1[i]*nums2[j]));

    p=max(p,find(i+1,j,k,nums1,nums2,dp));
    p=max(find(i,j+1,k,nums1,nums2,dp),p);

    return dp[i][j][k]=p;






}

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<vector<long long>>> dp(nums1.size(),vector<vector<long long>> (nums2.size(),vector<long long> (k+1,1e15)));
        return find(0,0,k,nums1,nums2,dp);

    }
};