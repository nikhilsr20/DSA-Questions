

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       vector<int> indegree(graph.size(),0);
       vector<vector<int>> adj(graph.size());

       for(int i=0;i<graph.size();i++){
              indegree[i]=graph[i].size();
            //   cout<<"indegree["<<i<<"]"<<"--"<<graph[i].size()<<endl;
              for(int j=0;j<graph[i].size();j++){
                    adj[graph[i][j]].push_back(i);
              }
       }

       queue<int> a;
       vector<int> ans;
       for(int i=0;i<indegree.size();i++){
        cout<<"indegree["<<i<<"]"<<"--"<<graph[i].size()<<endl;
        if(indegree[i]==0){
        a.push(i);
          while(!a.empty()){
            int x=a.front();
             indegree[x]--;
            ans.push_back(x);
            a.pop();
            for(int j=0;j<adj[x].size();j++){
                 indegree[adj[x][j]]--;
                 if(indegree[adj[x][j]]==0){
                    a.push(adj[x][j]);
                 }
            }
           

          }

        }
       }

       sort(ans.begin(),ans.end());
       return ans;
    }
};