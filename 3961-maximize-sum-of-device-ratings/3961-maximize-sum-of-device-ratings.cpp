class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m=INT_MAX;

        
        if(units[0].size()==1){
            long long ans=0;
        for(int i=0;i<units.size();i++){
               ans+=units[i][0];
        }
        return ans;
        }
        for(int i=0;i<units.size();i++){
          sort(units[i].begin(),units[i].end());
        }

        for(int i=0;i<units.size();i++){
            m=min(m,units[i][0]);
        }

        long long total=0;

        for(int i=0;i<units.size();i++){
                total+=units[i][1];
        }
        long long ans=0;

         for(int i=0;i<units.size();i++){
                 long long p=total-units[i][1];
                 ans=max(ans,p+m);
         }
         return ans;



    }
};