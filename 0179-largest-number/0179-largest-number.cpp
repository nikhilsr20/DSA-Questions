class Solution {
public:
    string largestNumber(vector<int>& nums) {
            vector<string> a;
            for(int i=0;i<nums.size();i++){
                a.push_back(to_string(nums[i]));
            }
            sort(a.begin(), a.end(), [](const string &a, const string &b){
               
                     return a + b > b + a; 
                
              });
              if(a[0] == "0") return "0";
            string ans;
            for(int i=0;i<a.size();i++){
                ans+=a[i];
            }
            
            return ans;
    }
};
