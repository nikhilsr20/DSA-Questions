class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string s;
      
        int size=nums.size();
        vector<bool> v(size,false);
        for(int i=0;i<nums.size();i++){
             int zero=0;
          
              for(int j=0;j<nums.size();j++){
                string a=nums[j];
                if(v[j]==false){
                    if(a[i]=='0'){
                           v[j]=true;
                            zero++;
                    }
                }
              }
              if(zero>0){
                s+='1';
              }
              else{
                s+='0';
              }
             
            
        }

        return s;
    }
};