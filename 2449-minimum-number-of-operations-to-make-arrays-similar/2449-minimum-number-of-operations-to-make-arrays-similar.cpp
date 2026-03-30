class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        long long down=0;
        long long up=0;

        long long i=0;
        long long j=0;

        while(i<nums.size() && j<nums.size())
        {
            if(nums[i]%2==0 && target[j]%2==0){
               if(nums[i]<target[j]){
                  up+=abs(target[j]-nums[i])/2;
               }
               else if (nums[i]>target[j]){
                down+=abs(target[j]-nums[i])/2;
               }
               i++;
               j++;
               continue;
            }

            if(nums[i]%2!=0){
                i++;
            }
            if(target[j]%2!=0){
                j++;
            }
        }

        i=0;
        j=0;

        while(i<nums.size() && j<nums.size())
        {
            if(nums[i]%2==1 && target[j]%2==1){
               if(nums[i]<target[j]){
                  up+=abs(target[j]-nums[i])/2;
               }
               else if (nums[i]>target[j]){
                down+=abs(target[j]-nums[i])/2;
               }
               i++;
               j++;
               continue;
            }

            if(nums[i]%2!=1){
                i++;
            }
            if(target[j]%2!=1){
                j++;
            }
        }


      
        
        return down;

       
       
        
   





        
    }
};