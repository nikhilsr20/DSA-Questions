class Solution {
public:
    int findCircleNum(vector<vector<int>>& a) {
        vector<bool> visited(a.size() , false);
        int count=0;

        vector<vector<int>> adj(a.size());
        for(int i=0;i<a.size();i++){
             for(int j=0;j<a[0].size();j++){
                if(a[i][j]==1){
              adj[i].push_back(j);
              adj[j].push_back(i);
          
                }
        }
        }
       
  

  
         queue<int> x;
        for(int i=0;i<a.size();i++){
            if(visited[i]==false){
                count++;
            
             x.push(i);
             visited[i]=true;
             while(!x.empty()){
             int u=x.front();
             x.pop();
              for(int j=0;j<adj[u].size();j++){
                if(visited[adj[u][j]]==false){
                 visited[adj[u][j]]=true;
                 x.push(adj[u][j]);
                }
              }

             }
             while(!x.empty()){
        x.pop();
    }
          
            }
             
             

        }
        return count;
    }
};