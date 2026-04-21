void find(unordered_map<int,int> &a,int x){
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            a[i]++;
            if(x!=i*i){
                 a[(x/i)]++;
            }
        }
    }
}



class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int,int> a;
        long long ans=0;
        for(int i=0;i<nums.size();i++){

            if(nums[i]%k==0){
              ans+=(i);
            }
            else{
                ans+=a[(k/(__gcd(k,nums[i])))];
            }
           

            find(a,nums[i]);
        }
        return ans;
    }
};