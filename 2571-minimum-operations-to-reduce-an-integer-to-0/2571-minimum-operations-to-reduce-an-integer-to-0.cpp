class Solution {
public:
    int minOperations(int n) {
        int ans=0;
        while(n!=0){
            int count=0;
            if((n&1)==0){
                n=n>>1;
                continue;
            }

            while((n&1)==1){
                count++;
                n=n>>1;
            }
            if(count>=2){
                ans++;
               
            n=n|1;
            
            }
            if(count==1){
                ans++;
            }
            
        }
        return ans;
    }
};