class Solution {
public:
    int find(int x){
        for(int i = 2; i * i <= x; i++){
            if(x % i == 0){
                return i;
            }
        }
        return x;
    }

    int minOperations(vector<int>& nums) {
        int count = 0;
        
        for(int i = nums.size()-2; i >= 0; i--){
            
            while(nums[i] > nums[i+1]){
                int newVal = find(nums[i]);
                
          
                if(newVal == nums[i]) return -1;
                
                nums[i] = newVal;
                count++;
            }
        }
        return count;
    }
};