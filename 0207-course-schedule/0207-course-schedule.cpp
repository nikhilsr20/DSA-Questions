bool check(vector<int> &visited,vector<vector<int>> &adj,int i){
    visited[i]=1;
    int l=true;
    for(int j=0 ;j<adj[i].size();j++){
        int x=adj[i][j];
        if(visited[x]==-1){
            //    visited[x]=1;
               l=l&check(visited,adj,x);
        }
        // if(visited[x]==0){
        //     visited[i]=0;
        //     return true;
        // }
        else if(visited[x]==1){
         
            return false;
        }
    }
    visited[i]=0;
    return l;
}



class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        for(int i=0;i<p.size();i++){
           adj[p[i][0]].push_back(p[i][1]);
        }
        vector<int> visited(n,-1);
          int ans=true;
        for(int i=0;i<n;i++){
          if(visited[i]==-1){
            ans = ans & check(visited,adj,i);
          }
        }
        return ans;
    }
};