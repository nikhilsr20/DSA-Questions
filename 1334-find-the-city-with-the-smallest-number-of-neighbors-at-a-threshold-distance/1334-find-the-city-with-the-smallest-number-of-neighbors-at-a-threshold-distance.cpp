class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dist) {
        int currmax=INT_MAX;
        int currcity=-1;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
            queue<pair<int,int>> q;
            unordered_set<int> ans;
            vector<int> maxval(n,INT_MAX);
        for(int i=0;i<n;i++){
            q.push({i,0});
            maxval[i]=0;
            ans.insert(i);

            while(!q.empty()){
                int x=q.front().first;
                int y=q.front().second;
      
                 q.pop();
                for(int j=0;j<adj[x].size();j++){
                   
                    if(adj[x][j].second+y<=dist && (maxval[adj[x][j].first]>adj[x][j].second+y)){
                        q.push({adj[x][j].first,adj[x][j].second+y});
                        ans.insert(adj[x][j].first);
                        maxval[adj[x][j].first]=adj[x][j].second+y;
                        
                    }
                }
            }
            cout<<ans.size()<<endl;

            if(currmax>=ans.size()){
                currmax=ans.size();
                currcity=i;
            }
            ans.clear();
            maxval.assign(n,INT_MAX);
            



        
        }
        return currcity;
    }
};