class Solution {
public:
    int find(int u,vector<int> &parent,vector<int> &parity){
        if(parent[u]!=u){
           int p=parent[u];
           parent[u]=find(p,parent,parity);
           parity[u]^=parity[p];
           
        }
        return parent[u];
    }
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        vector<int> parent(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int> parity(n,0);
        int count=0;

        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            
            int p=find(u,parent,parity);
            int q=find(v,parent,parity);

            if(p!=q){
                parent[p]=q;
                parity[p] = parity[u] ^ parity[v] ^ w;
                count++;
            }
            else{
               if((parity[u] ^ parity[v]) == w) {
                    count++;
                }
            }

        }
        return count;
    }
};