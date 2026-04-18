class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
       vector<int> a;
       int st=2;
       while(st>0){
        // cout<<st<<endl;
        if(st%2==0){
            if(st<=n){
                a.push_back(st);
                st+=2;
            }
            else{
                if(n%2==0){
                    st=n-1;
                }
                else{
                    st=n;
                }
            }
            
        }
        else{
            a.push_back(st);
            st-=2;
        }
       }

    
       long long ans=0;
       for(int i=1;i<a.size();i++){
            // cout<<a[i]<<"=="<<a[i-1]<<endl;
            ans+=1LL*a[i-1]*a[i];
       }
       if(n==edges.size()){
        ans+=2;
       }
       return ans;

    }
};