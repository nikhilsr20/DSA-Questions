class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        

        vector<bool> visit(n,false);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(visit[i]==false){
                queue<int> q;
                visit[i]=true;
                int count=1;
                q.push(i);

                while(!q.empty()){
                    int x=q.front();
                    q.pop();

                    for (int j=0;j<adj[x].size();j++){
                        int p=adj[x][j];
                        if(visit[p]==false){
                            count++;
                            visit[p]=true;
                            q.push(p);
                        }
                    }
                }

                ans.push_back(count);
                cout<<count<<endl;

            }
        }


        sort(ans.begin(),ans.end());

        int sum=accumulate(ans.begin(),ans.end(),0);

        long long ans1=0;

        for(int i=0;i<ans.size()-1;i++){
            sum-=ans[i];

            ans1+=(1LL*ans[i]*sum);


        }

        return ans1;





    }
};