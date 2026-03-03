// int find (vector<int> &nums,int i,vector<int> &dp){
//     if(i>=nums.size()){
//         return 0;
//     }
//     if(dp[i]!=-1){
//         return dp[i];
//     }
//     int p;
//     int q;

//       p=find(nums,i+2,dp)+nums[i];
//       q = find(nums,i+1,dp);

//       return dp[i]=max(p,q);
// }


int find(vector<int> &nums,int i,vector<int> &dp){
    dp[i]=nums[i];
    dp[i+1]=max(nums[i],nums[i+1]);
    for(int j=i+2;j<nums.size();j++){
        int pick=dp[j-2]+nums[j];
        int notpick=dp[j-1];
        dp[j]=max(pick,notpick);
    }
    return dp[nums.size()-1];
}
class Solution {
public:
    int rob(vector<int>& nums) {
        // tabulation
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        vector<int> dp(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);

        int c1=find(nums,1,dp);
        nums.pop_back();
        int c2=find(nums,0,dp2);

        return max(c1,c2);
        
    }
};