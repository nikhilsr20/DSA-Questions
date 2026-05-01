class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int ans=INT_MAX;
        // vector<int> visit(n,false);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
              adj[edges[i][0]].push_back(edges[i][1]);
              adj[edges[i][1]].push_back(edges[i][0]);
        }


        for(int i=0;i<n;i++){
            vector<int> visit(n,false);
            queue<pair<int,int>> a;
             unordered_map<int,int> map;
    
            if(!visit[i]){
                a.push({i,-1});
                visit[i]=true;
            }

  
            while(!a.empty()){
                int x=a.front().first;
                int y=a.front().second;
                a.pop();
          

                

                for(int j=0;j<adj[x].size();j++){
                    int p=adj[x][j];
                    if(p!=y){
                    if(!visit[p]){
                       a.push({p,x});
                       visit[p]=true;
                       map[p]=map[x]+1;
                    }
                    else{
                  
                        ans=min(ans,map[x]+1+map[p]);
                        break;
                    }
                    }
                }
             
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};