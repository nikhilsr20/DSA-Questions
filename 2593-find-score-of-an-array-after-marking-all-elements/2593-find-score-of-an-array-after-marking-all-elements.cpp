class Solution {
public:
    long long findScore(vector<int>& nums) {
        unordered_map<int,int> visit;
       vector<pair<int,int>> a;
        for(int i=0;i<nums.size();i++){
            a.push_back({nums[i],i});
        }
        sort(a.begin(),a.end(),[](const pair<int,int> &a,const pair<int,int> &b){
                  if(a.first==b.first){
                    return a.second<b.second;
                  }
                  return a.first<b.first;
        });
        long long ans=0;
        int i=0;
        while(i<a.size()){
            if(visit[a[i].second]==1){
                i++;
                continue;
            }
             ans+=nums[a[i].second];
             visit[a[i].second-1]=1;
             visit[a[i].second+1]=1;
             i++;
        }
        return ans;

    }
};