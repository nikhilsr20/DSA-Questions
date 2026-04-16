class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        multiset<int> a;
        
        int m=INT_MAX;
        for(int i=x;i<nums.size();i++){
             a.insert(nums[i-x]);
             auto it=a.lower_bound(nums[i]);
             if(it != a.end()){
             m=min(m,abs(nums[i]-*it));
             }
             if(it != a.begin()){
                it--;  
                m=min(m,abs(nums[i]-*it));
             }
       


        }
        return m;
    }
};