// int find(int x){
//     int st=log2(x);
//     for(int i=st;i>=1;i--){
//         if(x%(i*i)==0){
//             x=x/(i*i);
//             i=min((int)log2(x),i);
//         }
       
//     }
//     cout<<x<<endl;
//     return x;
// }

int find(int x){
    for(int i = 2; i * i <= x; i++){
        while(x % (i * i) == 0){
            x /= (i * i);
        }
    }
    return x;
}

class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        unordered_map<int,long long> ans;

        for(int i=0;i<nums.size();i++){
            ans[find(i+1)]+=(1LL*nums[i]);
        }

        long long m=0;

        for(auto i : ans){
            m=max(m,i.second);
        }
        return m;
    }
};