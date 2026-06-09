class Solution {
public:
    int countTriplets(vector<int>& nums) {
        
        unordered_map<int,int> a;

        int count=0;

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
             int x=nums[i]&nums[j];
             a[x]++;
        }
        }

  

         for(int i=0;i<nums.size();i++){
                  int x=nums[i];
              for(auto i : a){
                int y=i.first;

                if((x&y)==0){
                    count+=i.second;
                }
              }
         }
         return count;


    }
}; 