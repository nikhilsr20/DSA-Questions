const int MOD=1000000007;

class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<pair<int,int>> s;
        for(int i=0;i<nums1.size();i++)
        {   if(nums1[i]!=0 && nums0[i]!=0){
            s.push_back({nums1[i],nums0[i]});
        }
        }        


        sort(s.begin(),s.end(),[](auto &a,auto &b){
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
            
        });
         for(int i=0;i<nums1.size();i++)
        {   if(nums0[i]==0){
            s.push_back({nums1[i],nums0[i]});
        }
        }    
        reverse(s.begin(),s.end());
        for(int i=0;i<nums1.size();i++)
        {   if(nums1[i]==0){
            s.push_back({nums1[i],nums0[i]});
        }
        }    
        reverse(s.begin(),s.end());



       
     
        long long mul=0;
        long long ans=0;
         for(int i=0;i<s.size();i++){
            int one=s[i].first;
            int zero=s[i].second;
            cout<<one<<"-"<<zero<<endl;
             for(int j=0;j<zero;j++){
                 if(mul==0){
                     mul=1;
                 }
                 else{
                     mul = (mul * 2) % MOD;
                 }
             }
              for(int j=0;j<one;j++){
                 if(mul==0){
                     mul=1;
                 }
                 else{
                    mul = (mul * 2) % MOD;
                 }
                  ans+=mul;
                  ans=ans%MOD;
             }
             
         }   


        return ans;
        
    }
};