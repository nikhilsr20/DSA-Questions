class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& m) {
        for(int j=0;j<m[0].size();j++){
            int count=0;
            for(int i=0;i<m.size();i++){
                if(m[i][j]==0){
                    count=0;

                }
                else{
                    count++;
                }
                m[i][j]=count;
              
               

        }
        }

        for(int i=0;i<m.size();i++){
            sort(m[i].rbegin(),m[i].rend());
              
        }

       int ans=INT_MIN;
       for(int i=0;i<m.size();i++){
         
        int p=m[i][0];

            for(int j=0;j<m[0].size();j++){
              p=min(m[i][j],p);
      
              ans=max(ans,p*(j+1));

        }
        }
        return ans;

    }
};