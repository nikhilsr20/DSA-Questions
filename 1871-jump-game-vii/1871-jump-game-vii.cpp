class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool> dp(s.size(),false);
        dp[0]=true;
      
        int t=0;
        int f=0;
         for(int i=minJump;i<s.size();i++){
            
            if(i-maxJump-1>=0){
             if(dp[i-maxJump-1]==true && s[i-maxJump-1]=='0'){
                t--;
             }
             else if(dp[i-maxJump-1]==false && s[i-maxJump-1]=='0'){
                f--;
             }
            }


             if(dp[i-minJump]==true && s[i-minJump]=='0'){
                t++;
             }
             else if(dp[i-minJump]==false && s[i-minJump]=='0'){
                f++;
             }

             if(t>0 && s[i]=='0'){
                dp[i]=true;
             }

         }
        return dp[s.size()-1];

    }
};