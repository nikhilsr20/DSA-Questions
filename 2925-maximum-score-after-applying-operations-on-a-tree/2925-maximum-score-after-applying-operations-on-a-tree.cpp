long long find(vector<vector<int>> &adj,int i,vector<int> &values,int par){
    long long add=INT_MAX;
    for(int j=0;j<adj[i].size();j++){
        if(adj[i][j]==par){
            continue;
        }
        if(add==INT_MAX){
            add=0;
        }
        add+=find(adj,adj[i][j],values,i);
    }
  
    return min(add,(long long)values[i]);
}


class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        long long sum=accumulate(values.begin(),values.end(),0LL);
        vector<vector<int>> adj(values.size());

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);

        }

        return sum-find(adj,0,values,-1);
    }
};