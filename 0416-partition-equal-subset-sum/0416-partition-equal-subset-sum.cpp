// int find(int &need,int curr,vector<int> &nums,int i,vector<vector<int>> &dp){
//     if(curr>need){
//         return 0;
//     }
//     if(i==nums.size()){
//         if(curr==need){
//             return 1;
//         }
//         return 0;
//     }

//     if(dp[i][curr]!=-1){
//         return dp[i][curr];
//     }
//     int x=find(need,curr+nums[i],nums,i+1,dp);
//     int y=find(need,curr,nums,i+1,dp);
    
//     return dp[i][curr]=x|y;

// }

int find(int &need,vector<int> &nums, vector<int> &dp){
    dp[0]=1;

    for(int i=0;i<nums.size();i++){
        // if(nums[i]<=need){
        // dp[nums[i]]=1;
        // }
        // else{
        //     return 0;
        // }
     for(int j=1;j<=need;j++){

        if(j-nums[i]>=0){
        dp[j]=dp[j-nums[i]]|dp[j];
        }
    }
    }
    return dp[need];

    

}


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // tabulation
    int sum=accumulate(nums.begin(),nums.end(),0);

    int need=sum/2;
    if(sum%2==1){
        return false;
    }
    // bool ans=false;
    vector<int> dp(need+1,0);
    int p=find(need,nums,dp);
    return p;



         
    }
};