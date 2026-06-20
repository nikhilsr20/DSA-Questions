class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
         restrictions.push_back({1,0});
           int m = restrictions.size();
        bool found = false;
        for(auto &r : restrictions){
            if(r[0] == n){
                found = true;
                break;
            }
        }
         if(!found){
            restrictions.push_back({n,n-1});
        }
        
        sort(restrictions.begin(),restrictions.end());

        for(int i=1;i<m;i++){
            int dist = restrictions[i][0] - restrictions[i-1][0];

            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i-1][1] + dist
            );
        }

        // Backward pass
        for(int i=m-2;i>=0;i--){
            int dist = restrictions[i+1][0] - restrictions[i][0];

            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i+1][1] + dist
            );
        }
        int curr=0;
        int pos=1;

        int ans=0;
        for(int i=0;i<restrictions.size();i++){
            int x=restrictions[i][1];

            int xpos=restrictions[i][0];
            int m;

           

            if(abs(curr-x)>=abs(xpos-pos) && x>curr){
               
                m=curr+abs(xpos-pos);
                curr=curr+abs(xpos-pos);
                ans=max(ans,m);
                pos=xpos;
                continue;
                
            }
            else{
                int totaldist=abs(xpos-pos);
                int fixneed=abs(curr-x);

                int overtake=(totaldist-fixneed);
                overtake=(overtake)/2;

                m=max(curr,x)+overtake;
            }

            curr=x;
            pos=xpos;

            ans=max(ans,m);
        

        }
        return ans;

       
    }
};