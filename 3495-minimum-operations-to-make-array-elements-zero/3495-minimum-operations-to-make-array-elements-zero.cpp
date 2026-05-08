long long find(long long left,long long right,long long l ,long long r,long long steps){
    // overlap
      if(right < l || left > r){
            return 0;
        }
    long long x=max(left,l);
    long long y=min(right,r);


   
      
        return 1LL*(y-x+1)*steps;
   
}


class Solution {
public:
    long long minOperations(vector<vector<int>>& q) {
       

        long long ans=0;
        
        for(int i=0;i<q.size();i++){
             long long count=0;
            long long left=1;
            long long right=3;
           



            long long l=q[i][0];
            long long r=q[i][1];
            
             long long steps = 1;
            
            while(left<=r){
            count+=(find(left,right,l,r,steps));
            left=right+1;
            right=((left)*4)-1;
            steps++;
            }

             ans += (count + 1) / 2;
            
           

        }
      
        return ans;
    }
};