class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        for(int i=0;i<nums.size();i++){
            float y=nums[i]+1;
             int x=nums[i];
            if(nums[i]==2){
                nums[i]=-1;
            }
            else if(log2(y)==log2(nums[i]+1)){
               
                nums[i]=(y/2)-1;
                
            }
            else{
            int count=0;
            int mul=1;

            while((x&1)==1){
                      count+=mul;
                      mul*=2;
                      x=x>>1;
            }
           

            if(count==1){
                nums[i]-=1;
            }
            else{
            nums[i]=nums[i]-((count+1)/2);
            }
            }
            

           
            
           

        }
        return nums;
    }
};